#!/usr/bin/env python

import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import sys

bridge = CvBridge()

def image_callback():
    print("Received an image.")
    global bridge

    try:
        cv_image = bridge.imgmsg_to_cv2(ros_image, "bgr8")

def main(args):
    rospy.init_node('image_converter_node', anonymous=True)

    image_sub = rospy.Subscriber("/usb_cam/image_raw", Image, image_callback)
     