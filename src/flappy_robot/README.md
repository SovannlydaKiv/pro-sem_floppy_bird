# Flappy Robot - ROS2 Mini Project

## Description
A Flappy Bird style game using ROS2. The robot must pass through pipe gaps.

## Requirements
- ROS2 Jazzy
- Ubuntu 24.04

## Build
cd ~/ros2_ws
colcon build --packages-select flappy_robot
source install/setup.bash

## Run
ros2 launch flappy_robot flappy.launch.py

## Controls
- SPACE or UP ARROW = Flap/Jump
- Ctrl+C = Quit

## Visualization
Open rviz2 in a new terminal:
rviz2
- Set Fixed Frame to: map
- Add MarkerArray display
- Set topic to: /visualization_marker_array

## Custom Message (FlappyStatus.msg)
- float32 vertical_velocity
- float32 horizontal_speed
- int32 score
- float32[] pipe_positions
- string game_over_reason

