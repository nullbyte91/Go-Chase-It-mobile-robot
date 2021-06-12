#include "drive_bot.hpp"

bool DriveBot::drive_bot(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{
    geometry_msgs::Twist motor_command;
    motor_command.linear.x = req.linear_x;     
    motor_command.angular.z = req.angular_z;

    // Publish the velocity value to service
    motor_command_publisher_.publish(motor_command);
    return true;
}

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");
    
    // Init ros nodes
    DriveBot driveBot;

    return 0;
}