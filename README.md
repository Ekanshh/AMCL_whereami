

This repo has reference to the project **Go Chase it** of the [Robotics Software Engineer Nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209) program offered by [Udacity](https://www.udacity.com/) and contains a mobile robot model that chases a white colored ball, simulated in Gazebo and Rviz.

## Description

The tree structure of the directories and files is as follows:
                                      
                                      ├── ball_chaser
                                      │   ├── CMakeLists.txt
                                      │   ├── launch
                                      │   │   └── ball_chaser.launch
                                      │   ├── package.xml
                                      │   ├── src
                                      │   │   ├── drive_bot.cpp
                                      │   │   └── process_image.cpp
                                      │   └── srv
                                      │       └── DriveToTarget.srv
                                      ├── LICENSE
                                      ├── my_robot
                                      │   ├── CMakeLists.txt
                                      │   ├── launch
                                      │   │   ├── robot_description.launch
                                      │   │   └── world.launch
                                      │   ├── meshes
                                      │   │   └── hokuyo.dae
                                      │   ├── package.xml
                                      │   ├── src
                                      │   ├── urdf
                                      │   │   └── my_robot.urdf
                                      │   └── world
                                      │       ├── empty.world
                                      │       └── test.world
                                      └── README.md
                                      
## How-To-Build-The-Project

1. Clone this repository into the workspace.
2. Build the project using the following commands:
  ```
  $ cd /home/workspace/
  $ catkin_make
  $ source devel/setup.bash
  ```
3. Execute the project using the following commands:
  ```
  $ roslaunch my_robot world.launch 
  $ roslaunch ball_chaser ball_chaser.launch
  ```
4. For RVIZ Integration: 

   `Select: Global Options-> Fixed Frame-> Odom.`
   
   `Add Robot Model.`

   `Add Camera. Then Select Image Topic: /camera/rgb/image_raw.`
 
   
   `
   
 
