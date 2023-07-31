#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
    # Create a publisher object
    pub = rospy.Publisher('chatter', String, queue_size=10)

    # Create and initialize a ROS node
    rospy.init_node('talker', anonymous=True)

    # Publish the ROS message
    rate = rospy.Rate(1)

    i = 0
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % i
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
        i += 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass