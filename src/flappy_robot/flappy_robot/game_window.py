import rclpy
from rclpy.node import Node
from flappy_robot_msgs.msg import FlappyStatus
import pygame, sys, random
from ament_index_python.packages import get_package_share_directory
import os

class FlappyGameWindow(Node):
    def __init__(self):
        super().__init__('flappy_game_window')
        self.pub = self.create_publisher(FlappyStatus, '/flappy_status', 10)
        self.WIDTH = 800
        self.HEIGHT = 600
        self.FPS = 30
        self.GRAVITY = 0.5
        self.FLAP_FORCE = -10
        self.PIPE_SPEED = 4
        self.PIPE_GAP = 180
        self.PIPE_WIDTH = 70
        self.reset_game()
        self.bird_img = None
        self.timer = self.create_timer(0.033, self.publish_status)

    def reset_game(self):
        self.robot_x = 150
        self.robot_y = self.HEIGHT // 2
        self.robot_vel = 0
        self.score = 0
        self.game_over = False
        self.game_over_reason = ""
        self.started = False
        self.pipes = []
        self.spawn_pipe()
        self.spawn_pipe()

    def spawn_pipe(self):
        x = self.pipes[-1]['x'] + 280 if self.pipes else self.WIDTH + 100
        gap_y = random.randint(150, self.HEIGHT - 150)
        self.pipes.append({'x': x, 'gap_y': gap_y, 'scored': False})

    def flap(self):
        if self.game_over:
            self.reset_game()
        else:
            self.started = True
            self.robot_vel = self.FLAP_FORCE

    def update(self):
        if not self.started or self.game_over:
            return
        self.robot_vel += self.GRAVITY
        self.robot_y += self.robot_vel
        for pipe in self.pipes:
            pipe['x'] -= self.PIPE_SPEED
        for pipe in self.pipes:
            if not pipe['scored'] and pipe['x'] + self.PIPE_WIDTH < self.robot_x:
                pipe['scored'] = True
                self.score += 1
        self.pipes = [p for p in self.pipes if p['x'] > -self.PIPE_WIDTH]
        while len(self.pipes) < 3:
            self.spawn_pipe()
        if self.robot_y <= 0:
            self.game_over = True
            self.game_over_reason = "Flew too high"
        elif self.robot_y >= self.HEIGHT - 30:
            self.game_over = True
            self.game_over_reason = "Hit the ground"
        for pipe in self.pipes:
            if (self.robot_x + 30 > pipe['x'] and self.robot_x < pipe['x'] + self.PIPE_WIDTH):
                if (self.robot_y < pipe['gap_y'] - self.PIPE_GAP//2 or
                        self.robot_y + 30 > pipe['gap_y'] + self.PIPE_GAP//2):
                    self.game_over = True
                    self.game_over_reason = "Hit a pipe"

    def draw(self, screen, font, big_font):
        screen.fill((135, 206, 235))
        pygame.draw.rect(screen, (101, 67, 33), (0, self.HEIGHT-30, self.WIDTH, 30))
        pygame.draw.rect(screen, (34, 139, 34), (0, self.HEIGHT-35, self.WIDTH, 10))
        for pipe in self.pipes:
            gap_y = pipe['gap_y']
            top_h = gap_y - self.PIPE_GAP//2
            bot_y = gap_y + self.PIPE_GAP//2
            bot_h = self.HEIGHT - 30 - bot_y
            pygame.draw.rect(screen, (34, 139, 34), (pipe['x'], 0, self.PIPE_WIDTH, top_h))
            pygame.draw.rect(screen, (0, 100, 0), (pipe['x']-5, top_h-20, self.PIPE_WIDTH+10, 20))
            pygame.draw.rect(screen, (34, 139, 34), (pipe['x'], bot_y, self.PIPE_WIDTH, bot_h))
            pygame.draw.rect(screen, (0, 100, 0), (pipe['x']-5, bot_y, self.PIPE_WIDTH+10, 20))
        if self.bird_img:
            angle = max(-45, min(45, -self.robot_vel * 3))
            rotated = pygame.transform.rotate(self.bird_img, angle)
            screen.blit(rotated, (self.robot_x, int(self.robot_y)))
        else:
            pygame.draw.rect(screen, (255, 200, 0), (self.robot_x, int(self.robot_y), 35, 35))
        screen.blit(font.render(f"Score: {self.score}", True, (255,255,255)), (10, 10))
        screen.blit(font.render("ROS2 Flappy Robot", True, (255,255,255)), (self.WIDTH-200, 10))
        if not self.started and not self.game_over:
            msg = big_font.render("Press SPACE to Start!", True, (255,255,0))
            screen.blit(msg, (self.WIDTH//2 - msg.get_width()//2, self.HEIGHT//2 - 50))
        if self.game_over:
            for txt, col, dy in [("GAME OVER!", (255,0,0), -80),
                                  (self.game_over_reason, (255,255,255), -20),
                                  (f"Final Score: {self.score}", (255,255,0), 20),
                                  ("Press SPACE to Restart", (255,255,255), 60)]:
                s = (big_font if dy==-80 else font).render(txt, True, col)
                screen.blit(s, (self.WIDTH//2 - s.get_width()//2, self.HEIGHT//2 + dy))

    def publish_status(self):
        msg = FlappyStatus()
        msg.vertical_velocity = float(self.robot_vel)
        msg.horizontal_speed = float(self.PIPE_SPEED)
        msg.score = int(self.score)
        msg.pipe_positions = [float(p['x']) for p in self.pipes]
        msg.game_over_reason = self.game_over_reason
        self.pub.publish(msg)

    def run_game(self):
        pygame.init()
        screen = pygame.display.set_mode((self.WIDTH, self.HEIGHT))
        pygame.display.set_caption("Flappy Robot - ROS2")
        asset_path = os.path.join(get_package_share_directory('flappy_robot'), 'assets', 'bird.png')
        self.bird_img = pygame.image.load(asset_path).convert_alpha()
        self.bird_img = pygame.transform.scale(self.bird_img, (35, 35))
        clock = pygame.time.Clock()
        font = pygame.font.SysFont('Arial', 24)
        big_font = pygame.font.SysFont('Arial', 48, bold=True)
        while rclpy.ok():
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    rclpy.shutdown()
                    sys.exit()
                if event.type == pygame.KEYDOWN:
                    if event.key in (pygame.K_SPACE, pygame.K_UP):
                        self.flap()
            self.update()
            self.draw(screen, font, big_font)
            pygame.display.flip()
            clock.tick(self.FPS)
            rclpy.spin_once(self, timeout_sec=0)

def main(args=None):
    rclpy.init(args=args)
    node = FlappyGameWindow()
    node.run_game()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
