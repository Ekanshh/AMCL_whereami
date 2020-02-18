#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <iostream>
#include <math.h>

using namespace std;

//Define a global client that can request services
ros::ServiceClient client;

//This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{   
    //Print status
    //ROS_INFO_STREAM("Moving the robot towards the ball");

    //Request get intialized
    ball_chaser::DriveToTarget srv;

    srv.request.linear_x = lin_x;
    srv.request.angular_z= ang_z;
    
    //Print Error status
    if (!client.call(srv))
        ROS_ERROR("Failed to call service safe_move");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;
    int i=0,j=0;
    int move_left=0, move_fwd=0, move_right=0;
    int reached_target = 60000;

    //Loop through each pixel and compare it with white pixel
    for(int i=0;i<img.height;i++) 
    { 
       
        for(int j=0;j<img.step;j+=3)
        {
           
            if((img.data[(i*img.step)+j]==255) && (img.data[(i*img.step)+j+1]==255) && (img.data[(i*img.step)+j+2]==255))
            {  
                //Locating white pixel direction
                if(j<=(img.step/3))
                {
                    move_left++;
                }
                else if( j > (img.step/3) && j <= ((2*img.step)/3))
                {
                    move_fwd++;
                }
                else if (j > ((2*img.step)/3) && j<= img.step)
                {
                   move_right++;
            
                }
                else 
                {
                    ROS_ERROR("Failed to locate the white ball \n");
                }
            }
        }          
    }        

    //Calling service wrt to the direction of white pixel
    if ( move_left > move_fwd && move_left > move_right && move_left < reached_target)
    {   
        ROS_INFO("MOVING LEFTSIDE");
        drive_robot(0.05,0.3);
    }

    else if ( move_fwd > move_left && move_fwd > move_right && move_fwd < reached_target) 
    {   ROS_INFO("MOVING FORWARD");
        drive_robot(0.3,0.0);
    }

    else if ( move_right > move_left && move_right > move_fwd && move_right < reached_target)
    {   ROS_INFO("MOVING RIGHTSIDE");
        drive_robot(0.05,-0.3);
    }

    else
    {   ROS_INFO("STOP");
        drive_robot(0.0,0.0);        
    }

    //Printing the direction of white ball wrt to pixel density
    ROS_INFO(" The ball is : %d, %d, %d", move_left, move_fwd, move_right);
}


int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}