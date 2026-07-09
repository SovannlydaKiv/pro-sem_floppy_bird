import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from flappy_robot_msgs.msg import FlappyStatus
import random


class GameLogic(Node):
    def __init__(self):
        super().__init__('game_logic')
        self.pub = self.create_publisher(FlappyStatus, '/flappy_status', 10)
        self.sub = self.create_subscription(String, '/flappy_input', self.input_cb, 10)

        self.WIDTH = 800
        self.HEIGHT = 600
        self.FPS = 30
        self.GRAVITY = 0.5
        self.FLAP_FORCE = -10
        self.PIPE_SPEED = 4
        self.PIPE_GAP = 180
        self.PIPE_WIDTH = 70

        self.reset_game()

        # single timer drives both physics and publishing, same 30Hz cadence
        # as the old game_window loop
        self.timer = self.create_timer(1.0 / self.FPS, self.tick)

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

    def input_cb(self, msg):
        if msg.data != 'flap':
            return
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
                if (self.robot_y < pipe['gap_y'] - self.PIPE_GAP // 2 or
                        self.robot_y + 30 > pipe['gap_y'] + self.PIPE_GAP // 2):
                    self.game_over = True
                    self.game_over_reason = "Hit a pipe"

    def publish_status(self):
        msg = FlappyStatus()
        msg.vertical_velocity = float(self.robot_vel)
        msg.horizontal_speed = float(self.PIPE_SPEED)
        msg.robot_y = float(self.robot_y)
        msg.score = int(self.score)
        msg.started = bool(self.started)
        msg.pipe_positions = [float(p['x']) for p in self.pipes]
        msg.pipe_gap_y = [float(p['gap_y']) for p in self.pipes]
        msg.game_over_reason = self.game_over_reason
        self.pub.publish(msg)

    def tick(self):
        self.update()
        self.publish_status()


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(GameLogic())
    rclpy.shutdown()


if __name__ == '__main__':
    main()