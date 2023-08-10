#!/usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
import math

def scan_callback(scan_data):
    min_value, min_index = min_range_index(scan_data.ranges)
    print("\nmin range value:", min_value)
    print("min range index:", min_index)

    max_value, max_index = max_range_index(scan_data.ranges)
    print("\nmax range value:", max_value)
    print("max range index:", max_index)

    average_value = average_range(scan_data.ranges)
    print("\naverage range:", average_value)

    average2 = average_between_indices(scan_data.ranges, 2, 7)
    print("\naverage between 2 indices:", average2)


def min_range_index(ranges):
    ranges = [x for x in ranges if not math.isnan(x)]
    return min(ranges), ranges.index(min(ranges))

    
def max_range_index(ranges):
    ranges = [x for x in ranges if not math.isnan(x)]
    return max(ranges), ranges.index(max(ranges))


def average_range(ranges):
    ranges = [x for x in ranges if not math.isnan(x)]
    return sum(ranges) / float(len(ranges))


def average_between_indices(ranges, i, j):
    ranges = [x for x in ranges if not math.isnan(x)]
    return sum(ranges[i:j+1]) / float(len(ranges[i:j+1]))


if __name__ == '__main__':
    rospy.init_node('scan_node', anonymous=True)
    rospy.Subscriber('scan', LaserScan, scan_callback)

    rospy.spin()