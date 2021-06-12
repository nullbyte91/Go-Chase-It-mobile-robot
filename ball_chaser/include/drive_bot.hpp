#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

class DriveBot{
    public:
        bool drive_bot(ball_chaser::DriveToTarget::Request& req, 
                    ball_chaser::DriveToTarget::Response& res);

        DriveBot(){
            // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
            motor_command_publisher_ = n_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

            // drive /ball_chaser/command_robot service 
            ros::ServiceServer service = n_.advertiseService("ball_chaser/command_robot", &DriveBot::drive_bot, this);

            // Handle ROS communication events
            ros::spin();
        }
    private:
        ros::NodeHandle n_; 
        ros::Publisher motor_command_publisher_;
};