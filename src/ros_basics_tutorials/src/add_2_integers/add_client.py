#!/usr/bin/env python

# 1. import the service request and response
from ros_basics_tutorials.srv import Add2Ints
from ros_basics_tutorials.srv import Add2IntsRequest
from ros_basics_tutorials.srv import Add2IntsResponse

import sys
import rospy


# 2. Create the service client proxy
# wait for the server to start (the client may send a request to a server that doesn't exist)
def add2ints_client(x, y):
    rospy.init_node('add2ints_client')

    # 2.1 wait for the service before start communication
    rospy.wait_for_service('add2ints_service')
    try:
        # 2.2 create a client(proxy) object
        add2ints = rospy.ServiceProxy('add2ints_service', Add2Ints)
        resp = add2ints(x, y)
        return resp.sum
    except rospy.ServiceException(e):
        print("Service call failed: %s" % e)


if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print("%s [x y]" % sys.argv[0])
        sys.exit(1)
    
    print("Requesting %s+%s..." % (x, y))
    result = add2ints_client(x, y)
    print("%s + %s = %s" % (x, y, result))
