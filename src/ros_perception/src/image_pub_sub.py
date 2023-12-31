#!/usr/bin/env python

import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import sys

bridge = CvBridge()

def image_callback(ros_image):
    print("Received an image.")
    global bridge

    try:
        cv_image = bridge.imgmsg_to_cv2(ros_image, "bgr8")
    except CvBridgeError as e:
        print(e)

    rows, cols, channels = cv_image.shape

    font = cv2.FONT_HERSHEY_SIMPLEX
    cv2.putText(cv_image, "Webcam Activated", (10, 350), font, 1, (255, 255, 255), 2, cv2.LINE_AA)
    cv2.imshow("Image window", cv_image)
    cv2.waitKey(0)


def main(args):
    rospy.init_node('image_converter_node', anonymous=True)

    image_sub = rospy.Subscriber("/usb_cam/image_raw", Image, image_callback)
    
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")

    cv2.destroyAllWindows()


if __name__ == '__main__':
    main(sys.argv)