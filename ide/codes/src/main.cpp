#include <Arduino.h>
int a,b,c;
int A,B,C,D;
void disp_7447(int D,int C,int B,int A)
{  
	digitalWrite(2,A);
}
void setup()
{
    pinMode(2,OUTPUT);
    pinMode(4,INPUT);
    pinMode(5,INPUT);
    pinMode(6,INPUT);
}    
void loop()
{
	a=digitalRead(4);
	b=digitalRead(5);
	c=digitalRead(6);
	A=(b || !c) && (a || !c);
	disp_7447(D,C,B,A);
}
