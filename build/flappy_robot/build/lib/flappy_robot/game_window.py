import rclpy
from rclpy.node import Node
from flappy_robot_msgs.msg import FlappyStatus
import pygame
import sys
import random
import threading

class FlappyGameWindow(Node):
    def __init__(self):
        super().__init__('flappy_game_window')

        # ROS2 Publisher
        self.pub = self.create_publisher(FlappyStatus, '/flappy_status', 10)

        # Game constants
        self.WIDTH      = 800
        self.HEIGHT     = 600
        self.FPS        = 30
        self.GRAVITY    = 0.5
        self.FLAP_FORCE = -10
        self.PIPE_SPEED = 4
        self.PIPE_GAP   = 180
        self.PIPE_WIDTH = 70

        self.reset_game()

        # ROS2 timer to publish status
        self.timer = self.create_timer(0.033, self.publish_status)
        self.get_logger().info("Flappy Robot Game Window started!")

    def reset_game(self):
        self.robot_x    = 150
        self.robot_y    = self.HEIGHT // 2
        self.robot_vel  = 0
        self.score      = 0
        self.game_over  = False
        self.game_over_reason = ""
        self.started    = False
        self.pipes      = []
        self.spawn_pipe()
        self.spawn_pipe()

    def spawn_pipe(self):
        if self.pipes:
            x = self.pipes[-1]['x'] + 280
        else:
            x = self.WIDTH + 100
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

        # Physics
        self.robot_vel += self.GRAVITY
        self.robot_y   += self.robot_vel

        # Move pipes
        for pipe in self.pipes:
            pipe['x'] -= self.PIPE_SPEED

        # Score
        for pipe in self.pipes:
            if not pipe['scored'] and pipe['x'] + self.PIPE_WIDTH < self.robot_x:
                pipe['scored'] = True
                self.score += 1
                self.get_logger().info(f"Score: {self.score}!")

        # Recycle pipes
        self.pipes = [p for p in self.pipes if p['x'] > -self.PIPE_WIDTH]
        while len(self.pipes) < 3:
            self.spawn_pipe()

        # Boundary collision
        if self.robot_y <= 0:
            self.game_over = True
            self.game_over_reason = "Flew too high"
        elif self.robot_y >= self.HEIGHT - 30:
            self.game_over = True
            self.game_over_reason = "Hit the ground"

        # Pipe collision
        for pipe in self.pipes:
            if (self.robot_x + 30 > pipe['x'] and
                    self.robot_x < pipe['x'] + self.PIPE_WIDTH):
                if (self.robot_y < pipe['gap_y'] - self.PIPE_GAP // 2 or
                        self.robot_y + 30 > pipe['gap_y'] + self.PIPE_GAP // 2):
                    self.game_over = True
                    self.game_over_reason = "Hit a pipe"

        if self.game_over:
            self.get_logger().info(
                f"GAME OVER: {self.game_over_reason} | Score: {self.score}")

    def draw(self, screen, font, big_font):
        # Background
        screen.fill((135, 206, 235))  # Sky blue

        # Ground
        pygame.draw.rect(screen, (101, 67, 33),
                         (0, self.HEIGHT - 30, self.WIDTH, 30))
        pygame.draw.rect(screen, (34, 139, 34),
                         (0, self.HEIGHT - 35, self.WIDTH, 10))

        # Pipes
        for pipe in self.pipes:
            gap_y    = pipe['gap_y']
            top_h    = gap_y - self.PIPE_GAP // 2
            bot_y    = gap_y + self.PIPE_GAP // 2
            bot_h    = self.HEIGHT - 30 - bot_y

            # Top pipe
            pygame.draw.rect(screen, (34, 139, 34),
                             (pipe['x'], 0, self.PIPE_WIDTH, top_h))
            pygame.draw.rect(screen, (0, 100, 0),
                             (pipe['x'] - 5, top_h - 20,
                              self.PIPE_WIDTH + 10, 20))

            # Bottom pipe
            pygame.draw.rect(screen, (34, 139, 34),
                             (pipe['x'], bot_y, self.PIPE_WIDTH, bot_h))
            pygame.draw.rect(screen, (0, 100, 0),
                             (pipe['x'] - 5, bot_y,
                              self.PIPE_WIDTH + 10, 20))

        # Robot (yellow square with eyes)
        pygame.draw.rect(screen, (255, 200, 0),
                         (self.robot_x, int(self.robot_y), 35, 35))
        pygame.draw.rect(screen, (50, 50, 50),
                         (self.robot_x + 2, int(self.robot_y) + 2, 31, 31), 2)
        pygame.draw.circle(screen, (255, 255, 255),
                           (self.robot_x + 24, int(self.robot_y) + 10), 7)
        pygame.draw.circle(screen, (0, 0, 0),
                           (self.robot_x + 26, int(self.robot_y) + 10), 4)

        # Score
        score_text = font.render(f"Score: {self.score}", True, (255, 255, 255))
        screen.blit(score_text, (10, 10))

        # ROS2 label
        ros_text = font.render("ROS2 Flappy Robot", True, (255, 255, 255))
        screen.blit(ros_text, (self.WIDTH - 200, 10))

        # Messages
        if not self.started and not self.game_over:
            msg = big_font.render("Press SPACE to Start!", True, (255, 255, 0))
            screen.blit(msg, (self.WIDTH//2 - msg.get_width()//2,
                              self.HEIGHT//2 - 50))

        if self.game_over:
            over  = big_font.render("GAME OVER!", True, (255, 0, 0))
            reason = font.render(self.game_over_reason, True, (255, 255, 255))
            sc    = font.render(f"Final Score: {self.score}", True, (255, 255, 0))
            rst   = font.render("Press SPACE to Restart", True, (255, 255, 255))
            screen.blit(over,   (self.WIDTH//2 - over.get_width()//2,   self.HEIGHT//2 - 80))
            screen.blit(reason, (self.WIDTH//2 - reason.get_width()//2, self.HEIGHT//2 - 20))
            screen.blit(sc,     (self.WIDTH//2 - sc.get_width()//2,     self.HEIGHT//2 + 20))
            screen.blit(rst,    (self.WIDTH//2 - rst.get_width()//2,    self.HEIGHT//2 + 60))

    def publish_status(self):
        msg = FlappyStatus()
        msg.vertical_velocity = float(self.robot_vel)
        msg.horizontal_speed  = float(self.PIPE_SPEED)
        msg.score             = int(self.score)
        msg.pipe_positions    = [float(p['x']) for p in self.pipes]
        msg.game_over_reason  = self.game_over_reason
        self.pub.publish(msg)

    def run_game(self):
        pygame.init()
        screen   = pygame.display.set_mode((self.WIDTH, self.HEIGHT))
        pygame.display.set_caption("Flappy Robot - ROS2")
        clock    = pygame.time.Clock()
        font     = pygame.font.SysFont('Arial', 24)
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

            # Spin ROS2 callbacks
            rclpy.spin_once(self, timeout_sec=0)

def main(args=None):
    rclpy.init(args=args)
    node = FlappyGameWindow()
    node.run_game()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
