/*Code by M.Shantipriya (works on termux)
March 19, 2023

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
	Node *A,*B,*C,*D,*O,*X,*tempX;
	Node *m1,*m2,*m3,*m4,*transofm1,*mult1;
	double f1,f2,f3,f4;
	double angleABC;
	int m=2,n=1,p=2,div1;
	
	//Points
	A=loadtxt("data/A.dat",m,n);		//A=r*[cos(0),sin(0)]
	B=loadtxt("data/B.dat",m,n);		//B=r*[cos(pi/3),sin(pi/3)]
	O=loadtxt("data/O.dat",m,n);		//O=[0,0] ----Center of Circle
	tempX=mat_val(O,2.0);
	X=mat_val(O,2.0);
	C=linalg_sub(X,A);				//C=2*O-A
	save("data/C.dat",C,m,n);
	D=linalg_sub(tempX,B);				//D=2*O-B
	save("data/D.dat",linalg_sub(tempX,B),m,n);
	
	
	//directional vectors
	m1=linalg_sub(A,B);
	m2=linalg_sub(B,C);
	m3=linalg_sub(C,D);
	m4=linalg_sub(D,A);

	
	//transpose of directional vector
	transofm1=transpose_matrix(m1);
	
	//norms
	f1=linalg_norm(m1,m,n);
	f2=linalg_norm(m2,m,n);
	f3=linalg_norm(m1,m,n);
	f4=linalg_norm(m1,m,n);

	//ANGLE ABC
	mult1=matmul(transofm1,m2,1,1);
	div1=mult1->value/(f1*f2);
	
	
	angleABC=acos(div1);

	//Proof for ABCD is rectangle 
	if (f1==f3 && mult1->value == 0)
	{
    		printf("AB=DC \n");
    		printf("ANGLE ABC=%lf\n",degrees(angleABC));
    		printf("ABCD is RECTANGLE\n");
    	}	
    	return 0;
}

