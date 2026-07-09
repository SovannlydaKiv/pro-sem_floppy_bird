import rclpy
from rclpy.node import Node
from flappy_robot_msgs.msg import FlappyStatus
from std_msgs.msg import String
import pygame, sys
from ament_index_python.packages import get_package_share_directory
import os


class FlappyGameWindow(Node):
    def __init__(self):
        super().__init__('flappy_game_window')

        # rendering-only constants (game_logic owns the simulation values)
        self.WIDTH = 800
        self.HEIGHT = 600
        self.FPS = 30
        self.PIPE_GAP = 180
        self.PIPE_WIDTH = 70

        self.pub = self.create_publisher(String, '/flappy_input', 10)
        self.sub = self.create_subscription(FlappyStatus, '/flappy_status', self.status_cb, 10)

        self.latest = None  # most recent FlappyStatus received
        self.bird_img = None

    def status_cb(self, msg):
        self.latest = msg

    def send_flap(self):
        msg = String()
        msg.data = 'flap'
        self.pub.publish(msg)

    def draw(self, screen, font, big_font):
        screen.fill((135, 206, 235))
        pygame.draw.rect(screen, (101, 67, 33), (0, self.HEIGHT - 30, self.WIDTH, 30))
        pygame.draw.rect(screen, (34, 139, 34), (0, self.HEIGHT - 35, self.WIDTH, 10))

        if self.latest is None:
            msg = font.render("Waiting for game_logic node...", True, (255, 255, 255))
            screen.blit(msg, (self.WIDTH // 2 - msg.get_width() // 2, self.HEIGHT // 2))
            return

        status = self.latest
        for x, gap_y in zip(status.pipe_positions, status.pipe_gap_y):
            top_h = gap_y - self.PIPE_GAP // 2
            bot_y = gap_y + self.PIPE_GAP // 2
            bot_h = self.HEIGHT - 30 - bot_y
            pygame.draw.rect(screen, (34, 139, 34), (x, 0, self.PIPE_WIDTH, top_h))
            pygame.draw.rect(screen, (0, 100, 0), (x - 5, top_h - 20, self.PIPE_WIDTH + 10, 20))
            pygame.draw.rect(screen, (34, 139, 34), (x, bot_y, self.PIPE_WIDTH, bot_h))
            pygame.draw.rect(screen, (0, 100, 0), (x - 5, bot_y, self.PIPE_WIDTH + 10, 20))

        robot_x = 150
        if self.bird_img:
            angle = max(-45, min(45, -status.vertical_velocity * 3))
            rotated = pygame.transform.rotate(self.bird_img, angle)
            screen.blit(rotated, (robot_x, int(status.robot_y)))
        else:
            pygame.draw.rect(screen, (255, 200, 0), (robot_x, int(status.robot_y), 35, 35))

        screen.blit(font.render(f"Score: {status.score}", True, (255, 255, 255)), (10, 10))
        screen.blit(font.render("ROS2 Flappy Robot", True, (255, 255, 255)), (self.WIDTH - 200, 10))

        if not status.started and not status.game_over_reason:
            msg = big_font.render("Press SPACE to Start!", True, (255, 255, 0))
            screen.blit(msg, (self.WIDTH // 2 - msg.get_width() // 2, self.HEIGHT // 2 - 50))

        if status.game_over_reason:
            for txt, col, dy in [("GAME OVER!", (255, 0, 0), -80),
                                  (status.game_over_reason, (255, 255, 255), -20),
                                  (f"Final Score: {status.score}", (255, 255, 0), 20),
                                  ("Press SPACE to Restart", (255, 255, 255), 60)]:
                s = (big_font if dy == -80 else font).render(txt, True, col)
                screen.blit(s, (self.WIDTH // 2 - s.get_width() // 2, self.HEIGHT // 2 + dy))

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
                        self.send_flap()

            # Block until game_logic's next physics tick arrives instead of
            # free-running our own clock — this makes game_logic's 30Hz timer
            # the single source of truth, so we render exactly once per tick
            # with no drift and no backlog/catch-up jumps.
            rclpy.spin_once(self, timeout_sec=1.0)

            self.draw(screen, font, big_font)
            pygame.display.flip()
            clock.tick(self.FPS)  # safety cap only, no longer paces movement


def main(args=None):
    rclpy.init(args=args)
    node = FlappyGameWindow()
    node.run_game()
    rclpy.shutdown()


if __name__ == '__main__':
    main()