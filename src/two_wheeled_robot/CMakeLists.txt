cmake_minimum_required(VERSION 3.8)
project(two_wheeled_robot)

find_package(ament_cmake REQUIRED)

install(DIRECTORY launch meshes rviz urdf worlds
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
