#!/usr/bin/env python

# 1. import the service request and response
from ros_basics_tutorials.srv import Add2Ints
from ros_basics_tutorials.srv import Add2IntsRequest
from ros_basics_tutorials.srv import Add2IntsResponse

import rospy

# 3. create the callback function
# callback function will be executed automatically everytime a new request is received
def handle_add2ints(req):
    print("Returning [%s + %s = %s]." % (req.a, req.b, (req.a + req.b)))
    return Add2IntsResponse(req.a + req.b)

# 2. create the service
def add2ints_server():
    rospy.init_node('add2ints_server')
    s = rospy.Service('add2ints_service', Add2Ints, handle_add2ints)
    print("Ready to add two integers...")
    rospy.spin()

if __name__ == "__main__":
    add2ints_server()