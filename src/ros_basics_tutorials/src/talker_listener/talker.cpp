#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){
    // Initiate new ROS node
    ros::init(argc, argv, "talker_node");

    // Create a publisher
    ros::NodeHandle n;
    ros::Publisher chatter_publisher = n.advertise<std_msgs::String>("chatter", 10);
    
    // # messages per second
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok()){
        // create a new string msg
        std_msgs::String msg;

        // string for the data
        std::stringstream ss;
        ss << "hello world " << count;
        // assign string data to ROS message
        msg.data = ss.str();

        // print the content in the terminal
        ROS_INFO("[Talker] I published %s\n", msg.data.c_str());
        
        // publish message
        chatter_publisher.publish(msg);
        
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}
