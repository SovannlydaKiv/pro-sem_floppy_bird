from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='flappy_robot',
            executable='game_logic',
            name='game_logic',
            output='screen'
        ),
        Node(
            package='flappy_robot',
            executable='game_window',
            name='game_window',
            output='screen'
        ),
        Node(
            package='flappy_robot',
            executable='visualization',
            name='viz_node',
            output='screen'
        ),
        ExecuteProcess(
            cmd=['rviz2'],
            output='screen'
        ),
    ])