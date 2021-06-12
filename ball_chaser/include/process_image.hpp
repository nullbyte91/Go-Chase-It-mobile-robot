#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

class ProcessImage{
    public:
        enum Side : uint8_t {LEFT, FORWARD, RIGHT, NO_BALL} side = NO_BALL;
        void drive_robot(float lin_x, float ang_z);
        void process_image_callback(const sensor_msgs::Image img);
        ProcessImage()
        {
            // Define a client service capable of requesting services from command_robot
            client = n_.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

            // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
            ros::Subscriber img_node_ = n_.subscribe("/camera/rgb/image_raw", 10, &ProcessImage::process_image_callback, this);

            // Handle ROS communication events
            ros::spin();
        }

    private:
        ros::NodeHandle n_; 
        ros::Subscriber img_node_;
        ros::ServiceClient client;
};