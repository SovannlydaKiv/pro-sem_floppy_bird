import math
import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray
from flappy_robot_msgs.msg import FlappyStatus
from ament_index_python.packages import get_package_share_directory
import os

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

        # 3D bird mesh marker
        bird = Marker()
        bird.header.frame_id = "map"
        bird.header.stamp = self.get_clock().now().to_msg()
        bird.ns = "robot"
        bird.id = 0
        bird.type = Marker.MESH_RESOURCE
        bird.action = Marker.ADD
        bird.pose.position.x = 0.0
        bird.pose.position.y = 0.0
        bird.pose.position.z = float(robot_z)

        # TRY 4: Small 30 degree turn around Z axis only (no X/Y tilt)
        bird.pose.orientation.x = 0.0
        bird.pose.orientation.y = 0.0
        bird.pose.orientation.z = 0.2588   # sin(15 deg)
        bird.pose.orientation.w = 0.9659   #cos(15 deg)

        bird.scale.x = 0.05
        bird.scale.y = 0.05
        bird.scale.z = 0.05
        pkg_path = get_package_share_directory('flappy_robot')
        bird.mesh_resource = f"file://{pkg_path}/meshes/bird.dae"
        bird.mesh_use_embedded_materials = True
        bird.color.a = 1.0
        markers.markers.append(bird)

        for i, px in enumerate(msg.pipe_positions):
            markers.markers.append(self.make_marker("pipes", i+1, Marker.CYLINDER, px, 2.5, 0.4, 0.4, 5.0, 0.2, 0.6, 1.0))
        markers.markers.append(self.make_marker("ground", 100, Marker.CUBE, 0, -0.25, 50.0, 5.0, 0.5, 0.6, 0.4, 0.1))
        self.pub.publish(markers)

def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(Visualization())
    rclpy.shutdown()
