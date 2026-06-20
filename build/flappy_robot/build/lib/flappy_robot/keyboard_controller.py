import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import sys, termios, tty

class KeyboardController(Node):
    def __init__(self):
        super().__init__('keyboard_controller')
        self.pub = self.create_publisher(String, '/flappy_input', 10)
        self.get_logger().info("Press SPACE or UP ARROW to flap! Ctrl+C to quit.")
        self.run()

    def get_key(self):
        fd = sys.stdin.fileno()
        old = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old)
        return ch

    def run(self):
        while rclpy.ok():
            key = self.get_key()
            msg = String()
            if key == ' ':
                msg.data = 'flap'
                self.pub.publish(msg)
            elif key == '\x1b':
                next2 = sys.stdin.read(2)
                if next2 == '[A':
                    msg.data = 'flap'
                    self.pub.publish(msg)
            elif key == '\x03':
                break

def main(args=None):
    rclpy.init(args=args)
    node = KeyboardController()
    rclpy.shutdown()
