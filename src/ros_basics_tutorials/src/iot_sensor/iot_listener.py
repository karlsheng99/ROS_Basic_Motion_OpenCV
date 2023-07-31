#!/usr/bin/env python

import rospy
from ros_basics_tutorials.msg import IoTmsg

def iot_sensor_callback(message):
    rospy.loginfo("IoT data received: (%d, %s, %.2f, %.2f)", 
        message.id, message.name, message.temperature, message.humidity)

def listener():
    # Create and initialize a ROS node
    rospy.init_node('iot_listener', anonymous=True)

    # Create a subscriber object
    rospy.Subscriber('iot_sensor_topic', IoTmsg, iot_sensor_callback)

    # Start listening
    rospy.spin()

if __name__ == '__main__':
    listener()