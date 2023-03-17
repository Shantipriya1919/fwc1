/*Code by M.Shantipriya (works on termux)
March 14, 2023

Link to License("https://github.com/Shantipriya1919/fwc1/blob/main/LICENSE")

In right triangle ABC, right angled at C, M is the mid-point of hypotenuse AB. C is joined to M and produced to a point D such that DM = CM. Point D is joined to point B (see Figure 1). Show that:
(i) ∆ AMC ≅ ∆ BMC
(ii) ∠ DBC is a right angle.
(iii)∆ DBC ≅ ∆ ACB
(iv)CM=(1/2)AB
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359

int main()
{
	//Declaring variables
	int a=4,b=3,m=2,n=1,p=2;
	double **A,**B,**C,**M,**D,**tempM,**X,**Y;
	double **m1,**m2,**m3,**m4,**m5,**m6,**m7,**m8,**m9,f1,f2,f3,f4,f5,f6,f7,f8,f9;
	double **transofm1,**transofm3,**transofm5,**transofm9,mult1,mult2,div1,div2,mult3,mult4;
	int div3,div4;
	double angleAMC,angleDMB,angleACB,angleDBC;
	
	A=loadtxt("a.dat",2,1);		
	B=loadtxt("b.dat",2,1);
	C=loadtxt("c.dat",2,1);
	X=linalg_add(A,B,m,n);
	M=scalar_mul(X,m,n,0.5);
	Y=mult_int(2,M,m,n);
	D=linalg_sub(Y,C,m,n);
	save_D(D,2,1);
	
	
	tempM=scalar_mul(X,m,n,0.5);
	
	m1=linalg_sub(A,tempM,m,n);
	m2=linalg_sub(C,tempM,m,n);
	m3=linalg_sub(D,tempM,m,n);
	m4=linalg_sub(B,tempM,m,n);
	m5=linalg_sub(A,C,m,n);
	m6=linalg_sub(C,B,m,n);
	m7=linalg_sub(D,C,m,n);
	m8=linalg_sub(A,B,m,n);
	m9=linalg_sub(D,B,m,n);
	
	
	transofm1=transpose(m1,m,n);
	transofm3=transpose(m3,m,n);
	transofm5=transpose(m5,m,n);
	transofm9=transpose(m9,m,n);
	
	f1=linalg_norm(m1,m);
	f2=linalg_norm(m2,m);
	f3=linalg_norm(m3,m);
	f4=linalg_norm(m4,m);
	f5=linalg_norm1(m5,m);
	f6=linalg_norm(m6,m);
	f7=linalg_norm(m7,m);
	f8=linalg_norm(m8,m);
	f9=linalg_norm(m9,m);
	
	mult1=matmul_1(transofm1,m2,n,m,p);
	div1=mult1/(f1*f2);

	mult2=matmul_1(transofm3,m4,n,m,p);
	div2=mult2/(f3*f4);
	
	mult3=matmul_1(transofm5,m6,n,m,p);
	div3=mult2/(f5*f6);
	
	mult4=matmul_1(transofm9,m6,n,m,p);
	div4=mult1/(f9*f6);
	
	angleAMC=acos(div1);
	angleDMB=acos(div2);
	angleACB=acos(div3);
	angleDBC=acos(div4);
	
	
	//(i) ∆ AMC ≅ ∆ BMD
	if (f1==f4 && angleAMC == angleDMB && f3==f2){
  		printf("(i) ∆ AMC ≅ ∆ BMD \n");
	}
	//(ii) ∠ DBC is a right angle.
	if ( mult4 == 0){
		printf("(ii) ∠ DBC=%lf \n",degrees(angleDBC));
	}
	//(iii)∆ DBC ≅ ∆ ACB
	if (f6==f6 && angleACB == angleDBC && f9==f5){
  		printf("(iii) ∆ DBC ≅ ∆ ACB\n");
  	}
	//(iv)CM=(1/2)AB
	if (f2 == (0.5)*(f8)) {
  		printf("(iv) CM=(1/2)AB\n");
  	}

	return 0;
}
	
