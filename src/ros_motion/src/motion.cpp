#include "ros/ros.h"
#include "geometry_msgs.msg/Twist.h"
#include "turtlesim/Pose.h"

void move(double speed, double distance, bool isForward){
    geometry_msgs::Twist vel_msg;
    
    if(isForward)
        vel_msg.linear.x = abs(speed);
    else
        vel_msg.linear.x = -abs(speed);
    
    double t0 = ros::Time::now().toSec();
    double current_distance = 0.0;
    ros::Rate loop_rate(100);
    do{
        velocity_publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_distance = speed * (t1 - t0);
        ros::spinOnce();
        loop_rate.sleep();
    }while(current_distance < distance);

    vel_msg.linear.x = 0;
    velocity_publisher.publish(vel_msg);
}

void rotate(double angular_speed, double relative_angle, bool clockwise){
    // TODO
}

int main(int argc, char **argv){
    ros::init(argc, argv, "turtlesim_motion_pose_node");
    ros::NodeHandle n;
    double speed, angular_speed;
    double distance, angle;
    bool isForward, clockwise;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, pose_callback);

    return 0;
}