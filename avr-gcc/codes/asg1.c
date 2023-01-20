#include<avr/io.h>
#include<stdbool.h>
int main(void){

bool a,b,c,f;
DDRB = 0b00000101; //8&9&10&11 as inputs
PORTB= 0b11100000;
DDRD = 0b00000100; //2as output


while(1)
   {
	   a = (PINB & (1<<PINB0)) == (1<<PINB0);	
	   b = (PINB & (1<<PINB1)) == (1<<PINB1);
	   c = (PINB & (1<<PINB2)) == (1<<PINB2);
	   f=(b||!c)&&(a||!c);
	   PORTD |= (f<<2);

   }

	return 0;
}
