/*Code by M.Shantipriya (works on termux)
March 18, 2023

Link to License("https://github.com/Shantipriya1919/fwc1/blob/main/LICENSE")

If θ is the angle between two vectors a and b ,then a.b ≥ 0 only when
(a) 0 < θ < pi/2
(b) 0 ≤ θ ≤ pi/2
(c) 0 < θ < pi
(d) 0 ≤ θ ≤ pi

*/



#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359


int main()
{	
	//declaring varaibles
	Node *a,*b;
	int m=2,n=1,atransposeb;
	
	
	//loading the matrices from text files data
	a=loadtxt("data/a.dat");		
	b=loadtxt("data/b.dat");
	
	
	//check the condition atransposeb>=0 for θ in range of 0 to 2*pi
	for (double i=0;i<=2*PI;i=i+PI/6)
	{
    		atransposeb=(cos(i))*(linalg_norm(a,m,n))*(linalg_norm(b,m,n));
    		if (atransposeb>=0)
    		{
    			printf("condition satisfied by angle=%lf,",degrees(i));
    			printf("for atransposeb=%d \n",atransposeb);
    		}
    		else
    		{
    			printf("condition not satisfied by angle=%lf,",degrees(i));
    			printf("for atransposeb=%d \n",atransposeb);
    		}
    	}
    	return 0;
}
