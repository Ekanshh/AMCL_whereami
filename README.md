

This repo has reference to the project **Where Am I** of the [Robotics Software Engineer Nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209) program offered by [Udacity](https://www.udacity.com/). This project focusses on the localisation of a robot using AMCL algorithm, in a gazebo-simulated mapped environment.

## Description

The tree structure of the directories and files is as follows:
                                                      .
                                                      ├── LICENSE
                                                      ├── myamcl
                                                      │   ├── CMakeLists.txt
                                                      │   ├── config
                                                      │   │   ├── base_local_planner_params.yaml
                                                      │   │   ├── costmap_common_params.yaml
                                                      │   │   ├── global_costmap_params.yaml
                                                      │   │   ├── local_costmap_params.yaml
                                                      │   │   └── __MACOSX
                                                      │   ├── include
                                                      │   │   └── myamcl
                                                      │   ├── launch
                                                      │   │   └── amcl.launch
                                                      │   ├── maps
                                                      │   │   ├── buildmyworld-og.pgm
                                                      │   │   ├── buildmyworld.pgm
                                                      │   │   └── buildmyworld.yaml
                                                      │   ├── package.xml
                                                      │   └── src
                                                      ├── my_robot
                                                      │   ├── CMakeLists.txt
                                                      │   ├── launch
                                                      │   │   ├── robot_description.launch
                                                      │   │   └── world.launch
                                                      │   ├── meshes
                                                      │   │   └── hokuyo.dae
                                                      │   ├── package.xml
                                                      │   ├── urdf
                                                      │   │   ├── my_robot.urdf
                                                      │   │   ├── robby.gazebo
                                                      │   │   └── robby.xacro
                                                      │   └── world
                                                      │       ├── buildmyworld
                                                      │       └── empty.world
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
  $ roslaunch myamcl amcl.launch
  ```
5. For RVIZ Integration: 

   `Select: Global Options-> Fixed Frame-> Map`

   `Add Robot Model.`
   
   `Add Camera. Then Select Image Topic: /camera/rgb/image_raw.`
   
   `Add LaserScan. Then Select Image Topic: /scan.`
   
   `Add Maps. Then Select Image Topic: /map. Check other maps such as /move_base/local_costmap/costmap /move_base/global_costmap/costmap`
   
   `Add PoseArrow. Then Select Topic: /pointcloud.`

   
## Screenshots-Of-The-Project

### At Origin
<img src='images/robot.png' height=500 />

### After giving 2D Nav Goal 
<img src='images/robot_2.png' height=500 />
   
 
