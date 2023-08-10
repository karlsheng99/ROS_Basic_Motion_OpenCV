#!/usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
import time

front_distance = float('inf')
left_distance = float('inf')
right_distance = float('inf')

def scan_callback(scan_data):
    global front_distance, left_distance, right_distance

    front_ranges = scan_data.ranges[-5:] + scan_data.ranges[:6]
    # front_average = sum(front_ranges) / len(front_ranges)
    front_average = min(front_ranges)
    print("Average front distance:", front_average)

    front_distance = front_average

    right_ranges = scan_data.ranges[265:276]
    left_ranges = scan_data.ranges[85:96]
    right_distance= sum(right_ranges) / len(right_ranges)
    left_distance= sum(left_ranges) / len(left_ranges)

    # print(left_distance, right_distance)



def move(vel_pub):
    global front_distance

    loop_rate = rospy.Rate(30)
    vel_msg = Twist()

    k_linear = 0.3

    print("The robot is moving forward.")

    while ((front_distance - 0.6) > 0.02):
        vel_msg.linear.x = min(k_linear * abs(front_distance - 0.5), 0.6)
        vel_pub.publish(vel_msg)
        loop_rate.sleep()

    print("Too close to an obstacle!")
    vel_msg.linear.x = 0
    vel_pub.publish(vel_msg)
    rotate(vel_pub)


def rotate(vel_pub):
    global front_distance

    loop_rate = rospy.Rate(30)
    vel_msg = Twist()

    k_angular = 0.2
    clearance = 3
    clockwise = 1

    print("The robot is rotating.")

    if (left_distance > right_distance):
        clockwise = 1
    else:
        clockwise = -1

    while (front_distance < (clearance - 0.15)):
        vel_msg.angular.z = clockwise * min(k_angular * abs(front_distance - clearance + 0.1), 0.4)
        vel_pub.publish(vel_msg)
        loop_rate.sleep()

    print("No obstacles within 3 meters in front!")
    vel_msg.angular.z = 0
    vel_pub.publish(vel_msg)



if __name__ == "__main__":
    rospy.init_node("move_stop_rotate_node", anonymous=True)
    rospy.Subscriber("scan", LaserScan, scan_callback)
    velocity_publisher = rospy.Publisher("cmd_vel", Twist, queue_size=10)
    
    time.sleep(2)

    while True:
        move(velocity_publisher)

    rospy.spin()
