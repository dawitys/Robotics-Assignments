#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from beginner_tutorials.srv import *

def add_two_ints_client(x, y, z, a,b,c,d):
    rospy.wait_for_service('multiply_matrix')
    try:
        add_two_ints = rospy.ServiceProxy('multiply_matrix', multiplymatrix)
        resp1 = add_two_ints(x, y, z, a,b,c,d)
        return resp1.sum
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
  
def usage():
    return "%s [x y]"%sys.argv[0]
  
if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
        z = int(sys.argv[3])
        a = int(sys.argv[4])
        b = int(sys.argv[5])
        c = int(sys.argv[6])
        d = int(sys.argv[7])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting %s+%s"%(x, y))
    print("%s + %s = %s"%(x, y, z, a,b,c,d, add_two_ints_client(x, y, z, a,b,c,d))))
