/*Code by M.Shantipriya (works on termux)
March 15, 2023

Link to License("https://github.com/Shantipriya1919/fwc1/blob/main/LICENSE")

Find the area of triangle formed by the lines y − x = 0, x + y = 0, and x − k = 0.

*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359

int main()
{
	//Declaring Variables
	int m=2,n=1;
	double c1,c2,c3,k=3,area_of_triangle;
	double **n1,**n2,**n3,**A,**B,**C;
	
	
	//constants for 3 line equations given
	c1=0;
	c2=0;
	c3=k;
	
	
	//Given line equations in matrix form
	n1=loadtxt("data/n1.dat",m,n);		
	n2=loadtxt("data/n2.dat",m,n);
	n3=loadtxt("data/n3.dat",m,n);
	
	
	//Intersection point of n1 and n2 lines
	A=line_intersect(n1,n2,c1,c2,m,n);
	save(A,m,n,"data/A.dat");
	
	//Intersection point of n2 and n3 lines
	B=line_intersect(n2,n3,c2,c3,m,n);
	save(B,m,n,"data/B.dat");
	
	//Intersection point of n3 and n1 lines
	C=line_intersect(n3,n1,c3,c1,m,n);
	save(C,m,n,"data/C.dat");
	
	
	//Find the Area of Triangle by using formula 
	area_of_triangle=(0.5)*cross(linalg_sub(A,B,m,n),linalg_sub(A,C,m,n));
	printf("area of triangle ABC=%lf\n",area_of_triangle);
	
	return 0;
}
