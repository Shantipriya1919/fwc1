import math
import numpy as np
import matplotlib.pyplot as plt
import subprocess
import shlex


A= np.loadtxt('data/A.dat',dtype='double')
B= np.loadtxt('data/B.dat',dtype='double')
C= np.loadtxt('data/C.dat',dtype='double')
M= np.loadtxt('data/M.dat',dtype='double')
D= np.loadtxt('data/D.dat',dtype='double')



#generating a line
def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB


#generating all lines
X_AB=line_gen(A,B)
X_CB=line_gen(C,B)
X_CA=line_gen(C,A)
X_DB=line_gen(D,B)
X_DC=line_gen(D,C)

#plotting all lines
plt.plot(X_AB[0,:],X_AB[1,:],label='AB')
plt.plot(X_CB[0,:],X_CB[1,:],label='BC')
plt.plot(X_CA[0,:],X_CA[1,:],label='AC')
plt.plot(X_DB[0,:],X_DB[1,:],label='DB')
plt.plot(X_DC[0,:],X_DC[1,:],label='DC')


#Labeling the coordinates
tri_coords =np.vstack((B,C,D,A,M)).T
plt.scatter(tri_coords[0,:],tri_coords[1,:])
vert_labels = ['B','C','D','A','M']
for i,txt in enumerate(vert_labels):
  plt.annotate(txt,(tri_coords[0,i],tri_coords[1,i]),
      textcoords="offset points",
      xytext=(0,10),
      ha='center')

plt.xlabel("X")
plt.ylabel("Y")
plt.grid()
plt.legend(loc='best')
plt.axis('equal')
plt.savefig('/sdcard/Download/codes/lines/9.7.1.8/figs/fig.pdf')
plt.show()

