/*Code by M.Shantipriya (works on termux)
March 13, 2023

Link to License("https://github.com/Shantipriya1919/fwc1/blob/main/LICENSE")

Find the magnitude of two vectors a and b , having the same magnitude and such that the angle between them is 60 degrees and their scalar product is 1/2.
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359 //pi value

int main()
{
	//The inputs
	double atransposeb=0.5;			//given atransposeb or scalar product is 1/2=0.5
	double theta=radians(60);		//given	angle between vector is 60 degrees	
	
	double a=sqrt(atransposeb/cos(theta));	//the formula for a is a={a(transpose)b\cos(theta)}^1/2
	double b=a;				//given b=a;
	
	
	//print values of a and b
	printf("a=%lf \n",a);
	printf("b=%lf \n",b);
	
	return 0;
}


	
