# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target flappy_robot_msgs::flappy_robot_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${flappy_robot_msgs_TARGETS}.
if(flappy_robot_msgs_TARGETS AND NOT TARGET flappy_robot_msgs::flappy_robot_msgs)
  add_library(flappy_robot_msgs::flappy_robot_msgs INTERFACE IMPORTED)
  set_target_properties(flappy_robot_msgs::flappy_robot_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${flappy_robot_msgs_TARGETS}")
endif()
