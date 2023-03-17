import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys
k= 3
#range of x
x=np.linspace(-1,5,10)
#1st line equation
y=x
#2nd line equation
y1=-x
#plot the 1st line equation -x+y=0
plt.plot(x,y,'r',label='y-x=0')

#plot the 2nd line equation x+y=0
plt.plot(x,y1,'b',label='x+y=0')

#plot the 3rd line equation x-k=0
plt.axvline(x=k,color='g',label='x-k=0')


A= np.loadtxt('a.dat',dtype='double')
B= np.loadtxt('b.dat',dtype='double')
C= np.loadtxt('c.dat',dtype='double')



#Labelling the coordinates
tri_coords = np.vstack((A,B,C)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels= ['A(0,0)','B(k,-k)','C(k,k)',]
for i, txt in enumerate(vert_labels):
 plt.annotate(txt, #this is text
     (tri_coords[0,i], tri_coords[1,i]), #this is the point to label
    textcoords="offset points" , # How to position the text
    xytext=(0,10),#Distance from the text to points (x,y)
    ha='center') # horizontal alignment can be left , right or center

plt.xlabel("X")
plt.ylabel("Y")
plt.legend(loc='best')
plt.grid()
plt.axis('equal')
plt.savefig('/sdcard/Download/codes/lines/11.10.4.8/figs/fig.pdf')
plt.show()
