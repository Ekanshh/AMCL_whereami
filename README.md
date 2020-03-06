
                                      
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
  $ roslaunch src/pkg_1/launch/world.launch
  $ roslaunch src/pkg_2/launch/amcl.launch
  ```

5. For RVIZ Integration: 

   `Select: Global Options-> Fixed Frame-> Map`
   
   `Add Robot Model, Camera, and Laser Scanner`

   `Add Map. Then select the topic /Map`
 
   
 
   
 
