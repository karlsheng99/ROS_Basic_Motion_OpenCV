#include "ros/ros.h"
#include "ros_basics_tutorials/Add2Ints.h"

// need to specify the request and response as parameters
bool add(ros_basics_tutorials::Add2Ints::Request &req,
         ros_basics_tutorials::Add2Ints::Response &res){
    res.sum = req.a + req.b;
    ROS_INFO("Returning [%ld + %ld = %ld].", (long int)req.a, (long int)req.b, (long int)res.sum);
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "add2ints_server_node");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add2ints_service", add);
    ROS_INFO("Ready to add two integers...");
    ros::spin();

    return 0;
}