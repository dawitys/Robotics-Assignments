#!/usr/bin/env python3

import tinyik as tik
import rospy
from std_msgs.msg import String
from arm_gazebo.srv import IK, IKResponse
import numpy as np
import sys


def handleIK(req):
    arm=tik.Actuator([
        'z',[0,0,0.15],
        'x',[0,0,2],
        'x',[0,0,1],
        'x',[0,0,0.5],
        'y',[0,0,0.2],
        'z',[0,0,0.1]
    ])
    arm.ee=ee
    # return arm.angles
    # angles = TC.ikTransform(req.links, req.ee)
    return IKResponse(arm.angles)

def ik_Server():
    rospy.init_node('IkServer')
    s = rospy.Service('ik', IK, handleIK)
    print('Ready to go...')
    rospy.spin()

if __name__ == '__main__':
    ik_Server()
