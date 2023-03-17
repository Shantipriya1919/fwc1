/*Code by M.Shantipriya (works on termux)
March 16, 2023

Link to License("https://github.com/Shantipriya1919/fwc1/blob/main/LICENSE")

If diagonals of a cyclic quadrilateral are diameters of the circle through the vertices of quadrilateral,prove that it is
a rectangle.

*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359

int main()
{	
	//Declaring variables
	double r=2;				//radius of circle
	double **A,**B,**C,**D,**O,**X,**tempX;
	double **m1,**m2,**m3,**m4,**transofm1,f1,f2,f3,f4,angleABC;
	int m=2,n=1,p=2,div1,mult1;
	
	//Points
	A=np_array(r*cos(0),r*sin(0));		//A=r*[cos(0),sin(0)]
	B=np_array(r*cos(PI/3),r*sin(PI/3));	//B=r*[cos(pi/3),sin(pi/3)]
	save(A,m,n,"data/A.dat");
	save(B,m,n,"data/B.dat");
	
	O=loadtxt("data/O.dat",m,n);		//O=[0,0] ----Center of Circle
	X=mult_int(2,O,m,n);
	tempX=mult_int(2,O,m,n);
	C=linalg_sub(X,A,m,n);			//C=2*O-A
	save(C,m,n,"data/C.dat");
	D=linalg_sub(tempX,B,m,n);		//D=2*O-B
	save(D,m,n,"data/D.dat");
	
	
	
	//directional vectors
	m1=linalg_sub(B,A,m,n);
	m2=linalg_sub(B,C,m,n);
	m3=linalg_sub(C,D,m,n);
	m4=linalg_sub(D,A,m,n);
	
	//transpose of directional vector
	transofm1=transpose(m1,m,n);
	
	//norms
	f1=linalg_norm(m1,m);
	f2=linalg_norm(m2,m);
	f3=linalg_norm(m1,m);
	f4=linalg_norm(m1,m);

	//ANGLE ABC
	mult1=matmul_1(transofm1,m2,n,m,p);
	div1=mult1/(f1*f2);
	
	
	angleABC=acos(div1);

	//Proof for ABCD is rectangle 
	if (f1==f3 && mult1 == 0)
	{
    		printf("AB=DC \n");
    		printf("ANGLE ABC=%lf\n",degrees(angleABC));
    		printf("ABCD is RECTANGLE\n");
    	}	
    	return 0;
}

