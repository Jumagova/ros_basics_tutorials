#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>
#include <math.h>

using namespace name;
ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;

const double x_min = 0.0;
const double y_min = 0.0;
const double x_max = 11.0;
const double y_max = 11.0;


void move(double speed, double distance, bool isForward);

int main (int argc, char **argv){
    ros::init (argc,argv, "turtlesim_cleaner");
    ros:: NodeHandle n;
    double speed, angular_speed;
    double distance, angle:
    double isForward, clockwise;

    velocity_publisher = m.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    pose_subscriner = n.subscribe("/turtle1/pose",10,poseCallback);

    ROS_INFO("\n\n\n *****START TESTING***** \n");
    ros::Rate loop_rate(0.5);

    ros::spin();
    return 0;
}

void move (double speed, double distance , bool isForward){
    geometry_msgs::Twist vel_msg;
    
    if (isForward){
        vel_msg.linear.x = abs(speed);
    } else {
        vel_msg.linear.x = -abs(speed);
    }

    double t0 = ros::Time::now().toSec();
    double current_distance = 0.0;
    do{
        velocity_publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_distance = speed * (t1 - t0)
        ros::spinOnce();
        loop_rate.sleep();
    } while (current_distance<distance);
    vel_msg_linear.x = 0;
    velocity_publisher.publish(vel_msg)
    }

    void rotate (double angular_speed, double relative_angle, bool clockwise){
        geometry_msgs::Twits vel_msg;

        if (clockwise){
            vel_msg.angular.z = -abs(angular_speed);
        } else{
            vel_msg.angular.z = abs (angular_speed);
        }

        double current_angle = 0.0;
        double t0 = ros::Time::now().toSec();
        ros::Rate loop_rate(10);

        do{
            velocity_publisher.publish(vel_msg);
            double t1 = ros::TIme::now().toSec();
            current angle = angular_speed*(t1-t0);
            ros::spinOnce();
            loop_rate.sleep()
        } while (current_angle<relative_angle);

        vel_msg.angular.z = 0;
        velocity_publisher.publish(vel_msg);
    }