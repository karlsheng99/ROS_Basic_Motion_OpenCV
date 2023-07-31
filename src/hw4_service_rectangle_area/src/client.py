#!/usr/bin/env python

from hw4_service_rectangle_area.srv import RectangleAreaService
from hw4_service_rectangle_area.srv import RectangleAreaServiceRequest
from hw4_service_rectangle_area.srv import RectangleAreaServiceResponse

import rospy
import sys

def rectangle_area_client(h, w):
    rospy.init_node("rectangle_area_client_node")

    rospy.wait_for_service("rectangle_area_service")
    try:
        service = rospy.ServiceProxy("rectangle_area_service", RectangleAreaService)
        response = service(h, w)
        area = response.area
        return area
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)


if __name__ == "__main__":
    if len(sys.argv) == 3:
        h = float(sys.argv[1])
        w = float(sys.argv[2])
    else:
        print("Usage: %s [height width]..." % sys.argv[0])
        sys.exit(1)
    
    print("Requesting the area of the rectangle with [height: %s, width: %s]" % (h, w))
    area = rectangle_area_client(h, w)
    print("The area is %.3f." % area)