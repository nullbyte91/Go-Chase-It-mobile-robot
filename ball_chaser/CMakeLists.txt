cmake_minimum_required(VERSION 3.0.2)
project(ball_chaser)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

find_package(OpenCV REQUIRED core imgproc)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  DriveToTarget.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  include
)

add_executable(drive_bot src/drive_bot.cpp)
target_link_libraries(drive_bot ${catkin_LIBRARIES})
add_executable(process_image src/process_image.cpp)
target_link_libraries(process_image ${catkin_LIBRARIES} ${OpenCV_LIBS})
