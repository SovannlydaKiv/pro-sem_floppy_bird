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
        self.reset_game()
        self.dt = 0.033
        self.timer = self.create_timer(self.dt, self.game_loop)
        self.get_logger().info("Game started! Press SPACE to flap!")

    def reset_game(self):
        self.robot_y = 5.0
        self.vel_y = 0.0
        self.gravity = -9.8
        self.flap_force = 6.0
        self.h_speed = 3.0
        self.pipe_x = [10.0, 20.0, 30.0]
        self.pipe_gap_y = [5.0, 4.5, 6.0]
        self.gap_size = 3.0
        self.score = 0
        self.game_over = False
        self.game_over_reason = ""

    def input_cb(self, msg):
        if msg.data == 'flap':
            if self.game_over:
                self.reset_game()
            else:
                self.vel_y = self.flap_force

    def game_loop(self):
        if self.game_over:
            return
        self.vel_y += self.gravity * self.dt
        self.robot_y += self.vel_y * self.dt
        self.pipe_x = [p - self.h_speed * self.dt for p in self.pipe_x]
        for i in range(len(self.pipe_x)):
            if self.pipe_x[i] < -2.0:
                self.pipe_x[i] = max(self.pipe_x) + 10.0
                self.pipe_gap_y[i] = 3.0 + random.uniform(0, 4.0)
                self.score += 1
        if self.robot_y <= 0.0:
            self.game_over = True
            self.game_over_reason = "Hit the ground"
        elif self.robot_y >= 10.0:
            self.game_over = True
            self.game_over_reason = "Flew too high"
        for i in range(len(self.pipe_x)):
            if abs(self.pipe_x[i]) < 0.5:
                if (self.robot_y < self.pipe_gap_y[i] - self.gap_size/2 or
                        self.robot_y > self.pipe_gap_y[i] + self.gap_size/2):
                    self.game_over = True
                    self.game_over_reason = "Hit a pipe"
        status = FlappyStatus()
        status.vertical_velocity = float(self.vel_y)
        status.horizontal_speed = float(self.h_speed)
        status.score = int(self.score)
        status.pipe_positions = [float(p) for p in self.pipe_x]
        status.game_over_reason = self.game_over_reason
        self.pub.publish(status)

def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(GameLogic())
    rclpy.shutdown()
