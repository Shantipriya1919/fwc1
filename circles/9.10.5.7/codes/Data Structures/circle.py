import numpy as np
import mpmath as mp
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys
#sys.path.insert(0,'/sdcard/Download/codes/circles/9.10.5.7/CoordGeo')
sys.path.insert(0,'/home/shantipriya/fwc-1/circles/9.10.5.7/CoordGeo')
#path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
#from conics.funcs import circ_gen
from conics.funcs import *

#if using termux
import subprocess
import shlex
#end if

r=2

A= np.loadtxt('data/A.dat',dtype='double')
B= np.loadtxt('data/B.dat',dtype='double')
C= np.loadtxt('data/C.dat',dtype='double')
O= np.loadtxt('data/O.dat',dtype='double')
D= np.loadtxt('data/D.dat',dtype='double')

##Generating the line 
xAC = line_gen(A,C)
xDB = line_gen(D,B)
xAD = line_gen(A,D)
xAB = line_gen(A,B)
xDC = line_gen(D,C)
xCB = line_gen(C,B)
##Generating the circle
x_circ= circ_gen(O,r)

#Plotting all lines
plt.plot(xAC[0,:],xAC[1,:],label='AC')
plt.plot(xDB[0,:],xDB[1,:],label='DB')
plt.plot(xAD[0,:],xAD[1,:],label='AD')
plt.plot(xAB[0,:],xAB[1,:],label='AB')
plt.plot(xDC[0,:],xDC[1,:],label='DC')
plt.plot(xCB[0,:],xCB[1,:],label='CB')
#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


	
#Labeling the coordinates
tri_coords = np.vstack((O,A,C,D,B)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','A','C','D','B']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(5,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('../figs/fig.pdf')
plt.show()




