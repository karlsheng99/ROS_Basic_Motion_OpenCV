#!/usr/bin/env python

import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


bridge = CvBridge()

def image_publisher(video_name):
    image_pub = rospy.Publisher('tennis_ball_image', Image, queue_size=10)
    rospy.init_node('video_publisher_node', anonymous=True)
    rate = rospy.Rate(20)

    while not rospy.is_shutdown():
        video_capture = cv2.VideoCapture(video_name)

        while(True):
            ret, frame = video_capture.read()

            image_msg = bridge.cv2_to_imgmsg(frame, encoding="passthrough")
            image_pub.publish(image_msg)
            rate.sleep()

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
            
        rate.sleep()



if __name__ == '__main__':
    video_name = "/home/ubuntu/catkin_ws/src/ros_perception/src/video/tennis-ball-video.mp4"
    try:
        image_publisher(video_name)
    except rospy.ROSInterruptException:
        pass
