import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray
from flappy_robot_msgs.msg import FlappyStatus

class Visualization(Node):
    def __init__(self):
        super().__init__('visualization')
        self.sub = self.create_subscription(FlappyStatus, '/flappy_status', self.status_cb, 10)
        self.pub = self.create_publisher(MarkerArray, '/visualization_marker_array', 10)

    def make_marker(self, ns, mid, mtype, x, z, sx, sy, sz, r, g, b):
        m = Marker()
        m.header.frame_id = "map"
        m.header.stamp = self.get_clock().now().to_msg()
        m.ns = ns
        m.id = mid
        m.type = mtype
        m.action = Marker.ADD
        m.pose.position.x = float(x)
        m.pose.position.y = 0.0
        m.pose.position.z = float(z)
        m.pose.orientation.w = 1.0
        m.scale.x = float(sx)
        m.scale.y = float(sy)
        m.scale.z = float(sz)
        m.color.r = float(r)
        m.color.g = float(g)
        m.color.b = float(b)
        m.color.a = 1.0
        return m

    def status_cb(self, msg):
        markers = MarkerArray()
        robot_z = msg.vertical_velocity * 0.1 + 5.0
        markers.markers.append(self.make_marker("robot", 0, Marker.CUBE, 0, robot_z, 0.5, 0.5, 0.5, 0.0, 1.0, 0.0))
        for i, px in enumerate(msg.pipe_positions):
            markers.markers.append(self.make_marker("pipes", i+1, Marker.CYLINDER, px, 2.5, 0.4, 0.4, 5.0, 0.2, 0.6, 1.0))
        markers.markers.append(self.make_marker("ground", 100, Marker.CUBE, 0, -0.25, 50.0, 5.0, 0.5, 0.6, 0.4, 0.1))
        self.pub.publish(markers)

def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(Visualization())
    rclpy.shutdown()
