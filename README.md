# Go Chase It! - Udacity - Robotics Software Engineer Nanodegree Program - Project Two

## Demo Videos

| 👉 [Go Chase It](https://www.youtube.com/watch?v=Tim4MBVdvsw) |
| ------------------------------------------------------------ |
| [![Go Chase It Demo](https://github.com/nullbyte91/go_chase_it_mobile_robot/blob/master/image/demo.png)](https://www.youtube.com/watch?v=Tim4MBVdvsw) |

## 🗃 Project structure

```python
.
├── ball_chaser
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── drive_bot.hpp
│   │   └── process_image.hpp
│   ├── launch
│   │   └── ball_chaser.launch
│   ├── package.xml
│   ├── src
│   │   ├── drive_bot.cpp
│   │   └── process_image.cpp
│   └── srv
│       └── DriveToTarget.srv
├── my_robot
│   ├── CMakeLists.txt
│   ├── launch
│   │   ├── robot_description.launch
│   │   └── world.launch
│   ├── meshes
│   │   └── hokuyo.dae
│   ├── model
│   │   └── ball
│   │       ├── model.config
│   │       └── model.sdf
│   ├── package.xml
│   ├── rviz
│   │   └── my_robot_config.rviz
│   ├── urdf
│   │   ├── my_robot.gazebo
│   │   └── my_robot.xacro
│   └── worlds
│       ├── empty.world
│       ├── test_world.world
│       ├── UdacityOffice_withball.world
│       └── UdacityOffice.world
└── README.md
```
## 🖖 Quick Start
```
mkdir -p catkin_ws/src && pushd catkin_ws/src
git clone https://github.com/nullbyte91/go_chase_it_mobile_robot.git 
cd ..

# Build package
catkin_make

# Terminal 1
source devel/setup.bash
roslaunch my_robot world.launch

# Terminal 2
source devel/setup.bash
roslaunch ball_chaser ball_chaser.launch
```
