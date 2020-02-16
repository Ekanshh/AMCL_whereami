#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
#include "my_robot/DriveToTarget.h"

ros::Publisher motor_command_publisher;

bool handle_move_request(my_robot::DriveToTarget::Request& req,
    my_robot::DriveToTarget::Response& res)
{
    //Print Service Request Call
    //ROS_INFO("DriveToTarget Request received - x:%1.2f, z:%1.2f", (float) req.linear_x, (float) req.angular_z);
    
    //initializing the variables
    float linear_val = req.linear_x;
    float angular_val = req.angular_z;

    //Publishing velocity command 
    geometry_msgs::Twist motor_command;

    motor_command.linear.x = linear_val;
    motor_command.angular.z = angular_val;
    motor_command_publisher.publish(motor_command);

    //Wait 3 seconds for arm to settle
    ros::Duration(3).sleep();

    //Return a response message
    res.msg_feedback = (" Robot is moving: "+ std::to_string((float)motor_command.linear.x))+","+ std::to_string((float)motor_command.angular.z);
    ROS_INFO_STREAM(res.msg_feedback);

    return true;
}



int main(int argc, char** argv)
{
    // Initialize the drive_bot node and create a handle to it
    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle n;

    // Define motor publishers to publish geometry_msgs::Twist messages on cmd_vel topic for motion
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // Service request
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_move_request);
    
    //Print ready status
    ROS_INFO("Ready to send motion commands");


    // Handle ROS communication events
    ros::spin();

    return 0;
}