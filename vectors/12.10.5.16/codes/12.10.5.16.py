from math import cos 
import numpy as np
import math
import sys
veca=np.array([4,3])
vecb=np.array([5,12])
for i in range(0,270,90):
  atransposeb=round(np.cos(i))*(np.linalg.norm(veca))*(np.linalg.norm(vecb))
  if atransposeb>=0:
    print("condition satisfied by angle=",i,"with magnitude",atransposeb)
  else:
    print("condition not satisfied by angle=",i,"with magnitude",atransposeb)
