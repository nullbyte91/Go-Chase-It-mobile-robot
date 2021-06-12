#include "process_image.hpp"

// This function calls the command_robot service to drive the robot in the specified direction
void ProcessImage::drive_robot(float lin_x, float ang_z)
{
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
    
    // Call the safe_move service and pass the requested joint angles
    if (!client.call(srv)) {
        ROS_ERROR("Failed to call service safe_move");
    }
}

// This callback function continuously executes and reads the image data
void ProcessImage::process_image_callback(const sensor_msgs::Image img)
{
    // Determine if there is a white ball and if yes, on which side
    for (int i = 0; i < img.height * img.step; i+=3) {
        auto red_channel   = img.data[i];
        auto green_channel = img.data[i+1];
        auto blue_channel  = img.data[i+2];

        if (red_channel == 255 && green_channel == 255 && blue_channel == 255) {
          auto pixel_val = i % img.step;
          if (pixel_val < img.step * 0.4) {
            side = LEFT;
          } else if (pixel_val > img.step * 0.6) {
            side = RIGHT;
          } else {
            side = FORWARD;
          }
          break;
        }
    }

    // Drive robot towards the ball
    if (side == LEFT) {
      drive_robot(0.5, 1.0);
    } else if (side == RIGHT) {
      drive_robot(0.5, -1.0);
    } else if (side == FORWARD) {
      drive_robot(0.5, 0.0);
    } else /* NO_BALL */ {
      drive_robot(0.0, 0.0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");

    ProcessImage processImage;
    return 0;
}