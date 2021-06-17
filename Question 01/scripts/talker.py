#!/usr/bin/env python
import numpy as nu
import math

from __future__ import print_function

from beginner_tutorials.srv import multiplymatrix,AddTwoIntsResponse
import rospy

def handle_add_two_ints(req):
    print("Returning the matrix transformation")
    return AddTwoIntsResponse(matrix_transform(req.x,req.y,req.z,req.a,req.b,req.c,req.d))

def matrix_transform(x,y,z,a,b,c,d):
    original = np.array([x,y,z])
    a,b,c = math.pi*a/180 , math.pi*b/180 , math.pi*c/180 
    rotatex = np.array([
        [1,0,0],
        [0,math.cos(a),-math.sin(a)],
        [0,math.sin(a),math.cos(a)]
    ])
    rotatey = np.array([
       [math.cos(b),0,math.sin(b)],
       [0,1,0],
       [-math.sin(b),0,math.cox(b)]
    ])
    rotatez = np.array([
        [math.cos(c),-math.sin(c),0],
        [math.sin(c),math.cos(c),0],
        [0,0,1]
    ])
    final = rotatex.dot(rotatey).dot(rotatez).dot(original)
    return final[0]+d, final[1]+ d, final[2]+d


  
def add_two_ints_server():
    rospy.init_node('multiply matrix server')
    s = rospy.Service('multiply_matrix', multiplymatrix, handle_add_two_ints)
    print("Ready to translate matrix ints.")
    rospy.spin()
  
if __name__ == "__main__":
    add_two_ints_server()
