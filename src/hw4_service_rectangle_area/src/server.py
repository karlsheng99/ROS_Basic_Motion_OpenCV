#!/usr/bin/env python

from hw4_service_rectangle_area.srv import RectangleAreaService
from hw4_service_rectangle_area.srv import RectangleAreaServiceRequest
from hw4_service_rectangle_area.srv import RectangleAreaServiceResponse

import rospy

def handle_area(request):
    print("Returning the area: [%.3f * %.3fs = %.3f]" % (request.height, request.width, (request.width * request.height)))
    response = RectangleAreaServiceResponse(request.width * request.height)
    return response

def rectangle_area_server():
    rospy.init_node("rectangle_area_server_node")
    rospy.Service("rectangle_area_service", RectangleAreaService, handle_area)
    print("Ready to compute the area of a rectangle...")
    rospy.spin()

if __name__ == "__main__":
    rectangle_area_server()