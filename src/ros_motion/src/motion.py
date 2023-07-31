#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math
import time

x = 0
y = 0
z = 0
yaw = 0


def pose_callback(pose_message):
    global x, y, yaw
    x = pose_message.x
    y = pose_message.y
    yaw = pose_message.theta


def move(velocity_publisher, speed, distance, is_forward):
    velocity_message = Twist()

    global x, y
    x0 = x
    y0 = y

    if(is_forward):
        velocity_message.linear.x = abs(speed)
        rospy.loginfo("Turtlesim is moving forward.")
    else:
        velocity_message.linear.x = -abs(speed)
        rospy.loginfo("Turtlesim is moving backward.")

    distance_moved = 0.0
    loop_rate = rospy.Rate(10)

    while True:
        velocity_publisher.publish(velocity_message)
        loop_rate.sleep()

        distance_moved = abs(math.sqrt((x - x0) ** 2 + (y - y0) ** 2))
        print("Distance moved: %.3f" % distance_moved)

        if not (distance_moved < distance):
            rospy.loginfo("Reached!")
            break

    velocity_message.linear.x = 0
    velocity_publisher.publish(velocity_message)


def rotate(velocity_publisher, angular_speed_degree, relative_angle_degree, clockwise):
    velocity_message = Twist()

    global yaw
    yaw0 = yaw

    angular_speed = math.radians(abs(angular_speed_degree))

    if(clockwise):
        velocity_message.angular.z = -abs(angular_speed)
        rospy.loginfo("Turtlesim is rotating clockwise.")
    else:
        velocity_message.angular.z = abs(angular_speed)
        rospy.loginfo("Turtlesim is rotating counterclockwise.")

    loop_rate = rospy.Rate(10)
    angle_moved = 0.0

    while True:
        velocity_publisher.publish(velocity_message)
        loop_rate.sleep()

        delta_angle_moved = abs(math.degrees(yaw) - math.degrees(yaw0))
        if (delta_angle_moved > 90):
            delta_angle_moved = 360 - delta_angle_moved
        
        angle_moved += delta_angle_moved
        print("Angle moved: %.3f" % angle_moved)

        yaw0 = yaw

        if not (angle_moved < relative_angle_degree):
            rospy.loginfo("Reached!")
            break

    velocity_message.angular.z = 0
    velocity_publisher.publish(velocity_message)        


def go_to_goal(velocity_publisher, x_goal, y_goal):
    velocity_message = Twist()

    global x, y, yaw
    loop_rate = rospy.Rate(10)

    while True:
        K_linear = 0.5
        error_distance = abs(math.sqrt(((x_goal - x) ** 2) + ((y_goal - y) ** 2)))
        linear_speed = error_distance * K_linear

        K_angular = 4.0
        target_angle = math.atan2(y_goal - y, x_goal - x)
        angular_speed = (target_angle - yaw) * K_angular

        velocity_message.linear.x = linear_speed
        velocity_message.angular.z = angular_speed
        velocity_publisher.publish(velocity_message)
        print('x =', x, '\ty =', y, '\tdistance to goal:', error_distance)

        if (error_distance < 0.01):
            break
        
        loop_rate.sleep()
    
    velocity_message.linear.x = 0
    velocity_message.angular.z = 0
    velocity_publisher.publish(velocity_message)


def setTargetOrientation(velocity_publisher, speed_degree, target_angle_degree):
    relative_angle_radian = math.radians(target_angle_degree) - yaw
    clockwise = 0
    if relative_angle_radian < 0:
        clockwise = 1

    print("Relative angle:", math.degrees(relative_angle_radian))
    print("Target angle:", target_angle_degree)
    rotate(velocity_publisher, speed_degree, math.degrees(abs(relative_angle_radian)), clockwise)


def spiral(velocity_publisher, wk, rk):
    velocity_message = Twist()

    global x, y

    loop_rate = rospy.Rate(1)

    while (x < 10.5 and y < 10.5):
        rk = rk + 0.3
        velocity_message.linear.x = rk
        velocity_message.angular.z = wk

        velocity_publisher.publish(velocity_message)
        loop_rate.sleep()

    velocity_message.linear.x = 0
    velocity_message.angular.z = 0
    velocity_publisher.publish(velocity_message)


def gridClean(velocity_publisher):
    pass

if __name__ == '__main__':
    try:
        rospy.init_node('turtlesim_motion_pose_node', anonymous=True)

        cmd_vel_topic = '/turtle1/cmd_vel'
        velocity_publisher = rospy.Publisher(cmd_vel_topic, Twist, queue_size=10)

        pose_topic = '/turtle1/pose'
        pose_subscriber = rospy.Subscriber(pose_topic, Pose, pose_callback)
        time.sleep(2)

        # move(velocity_publisher, 2, 4, False)
        # move(velocity_publisher, 2, 8, True)

        # rotate(velocity_publisher, 20, 90, False)
        # time.sleep(2)
        # rotate(velocity_publisher, 50, 360, False)
        # time.sleep(2)
        # rotate(velocity_publisher, 20, 90, True)
        # time.sleep(2)
        # rotate(velocity_publisher, 20, 90, True)

        # go_to_goal(velocity_publisher, 1, 1)
        # setTargetOrientation(velocity_publisher, 20, -120)

        spiral(velocity_publisher, 2, 0)

    except rospy.ROSInterruptException:
        rospy.loginfo("node terminated.")