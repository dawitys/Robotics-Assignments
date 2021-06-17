import numpy as np
def Rx(x):
    return np.array([
        [1,0,0,0],
        [0,np.cos(x), -np.sin(x), 0],
        [0,np.sin(x), np.cos(x), 0],
        [0,0,0,1]
    ])

def Ry(x):
    return np.array([
        [np.cos(x), np.sin(x), 0,0],
        [0,1,0,0],
        [-np.sin(x), np.cos(x), 1,0],
        [0,0,0,1]
    ])

def Rz(x):
    return np.array([
        [np.cos(x), -np.sin(x), 0,0],
        [np.sin(x), np.cos(x), 0,0],
        [0, 0, 1,0],
        [0,0,0,1]
    ])

def Translate(x,y,z):
    return np.array([
        [1,0,0,x],
        [0,1,0,y],
        [0,0,1,z],
        [0,0,0,1]
    ], dtype=np.float)
def fk(links,angles):
    m1=Translate(0,0,links[0])
    m2=Rz(np.radians(angles[0])).dot(Translate(0,0,links[1]))
    m3=Rx(np.radians(angles[1])).dot(Translate(0,0,links[2]))
    m4=Rx(np.radians(angles[2])).dot(Translate(0,0,links[3]))
    m5=Rx(np.radians(angles[3])).dot(Translate(0,0,links[4]))
    m6=Ry(np.radians(angles[4])).dot(Translate(0,0,links[5]))
    m7=Rz(np.radians(angles[5])).dot(Translate(0,0,links[6]))
    m=m1.dot(m2).dot(m3).dot(m4).dot(m5).dit(m6).dot(m7)

    return m[0, 3], m[1,3], m[2, 3]  