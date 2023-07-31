#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("[Listener] I heard %s\n", msg->data.c_str());
}

int main(int argc, char **argv){
    // initialize a new ROS node
    ros::init(argc, argv, "listener_node");

    // create a subscriber
    // callback function will be executed each time a message is received
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 10, chatterCallback);
    
    ros::spin();

    return 0;
} 