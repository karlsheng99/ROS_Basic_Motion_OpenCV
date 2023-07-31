#include "ros/ros.h"
#include "ros_basics_tutorials/Add2Ints.h"
#include <cstdlib>

int main(int argc, char **argv){
    ros::init(argc, argv, "add2ints_client_node");
    if (argc != 3){
        ROS_INFO("usage: %s [x y]", argv[0]);
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ros_basics_tutorials::Add2Ints>("add2ints_service");
    ros_basics_tutorials::Add2Ints service;
    service.request.a = atoll(argv[1]);
    service.request.b = atoll(argv[2]);

    ROS_INFO("Requesting %ld+%ld...", (long int)service.request.a, (long int)service.request.b);
    client.waitForExistence(ros::Duration(5.0));

    if (client.call(service)){
        ROS_INFO("%ld + %ld = %ld", (long int)service.request.a, (long int)service.request.b, (long int)service.response.sum);
    }
    else{
        ROS_ERROR("Failed to call service add2ints_service.");
        return 1;
    }
    return 0;
}