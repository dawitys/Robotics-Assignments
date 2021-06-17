#!/usr/bin/env python3

import rospy
from numpy import lib
from std_msgs.msg import String
from arm_gazebo.srv import FK, FKResponse
import numpy as np
import math
import kinematics.kinematics as TC


def handleIK(req):
    ee = TC.fkTransform(req.links, req.angles)
    return FKResponse(ee)

def fk_Server():
    rospy.init_node('FkServer')
    s = rospy.Service('fk', FK, handleIK)
    print('Ready to FK...')
    rospy.spin()

if __name__ == '__main__':
    fk_Server()
