#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def chatter_callback(message):
    rospy.loginfo("I heard %s" % message.data)

def listener():
    # Create and initialize a ROS node
    rospy.init_node('listener', anonymous=True)

    # Create a subscriber object
    rospy.Subscriber('chatter', String, chatter_callback)

    # Start listening
    rospy.spin()

if __name__ == '__main__':
    listener()