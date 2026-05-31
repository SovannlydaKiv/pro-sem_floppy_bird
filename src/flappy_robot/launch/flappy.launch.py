from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='flappy_robot', executable='game_logic', name='game_engine', output='screen'),
        Node(package='flappy_robot', executable='visualization', name='viz_node', output='screen'),
    ])
