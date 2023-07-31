#!/usr/bin/env python

import rospy
from ros_basics_tutorials.msg import IoTmsg
import random

def iot_talker():
    # Create a publisher object
    pub = rospy.Publisher('iot_sensor_topic', IoTmsg, queue_size=10)

    # Create and initialize a ROS node
    rospy.init_node('iot_talker', anonymous=True)

    # Publish the ROS message
    rate = rospy.Rate(1)

    i = 0
    while not rospy.is_shutdown():
        iot_message = IoTmsg()
        iot_message.id = 1
        iot_message.name = "iot_sensor_01"
        iot_message.temperature = 35 + (random.random() * 2)
        iot_message.humidity = 50 + (random.random() * 2)
        
        rospy.loginfo("I published: ")
        print(iot_message)
        pub.publish(iot_message)
        rate.sleep()
        i += 1

if __name__ == '__main__':
    try:
        iot_talker()
    except rospy.ROSInterruptException:
        pass