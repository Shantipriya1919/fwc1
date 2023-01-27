;POS expression operations
;output displayed using 7447 IC

.include "/sdcard/Download/codes/assignment1/assembly/codes/m328Pdef.inc"


ldi r17,0b11100011  ;declaring 2,3,4,5 pins as input pins
out DDRD,r17
ldi r17,0b11111111  ;  activating pull ups
out PORTD,r17

ldi r16,0b00100000    ;Declaring 13th pin as output pin
out DDRB,r16

main:

in r17,PIND          ; taking inputs from 2,3,4,5 pins of arduino

mov r18,r17        ;r18 is x0
mov r19,r17        ;r19 is x1
mov r22,r17        ; r22 is x2        ;r23 is x3

ldi r31,0b00000100    ; w c  
and r18,r31
ldi r20,0b00000010  ; counter=2
rcall loopa          ; shifting 2 bits right side
ldi r30,0b00001000   ;z   b
and r19,r30
ldi r21,0b00000011  ;counter=3
rcall loopb          ; shifting 3 bits right side
ldi r29,0b00010000   ;y  a
and r22,r29
ldi r16,0b00000100   ;counter=4
rcall loopc             ;shifting 4 bits right side         ; 
mov r24,r18           
ldi r27,0b00000001
eor r24,r27          ;r24=!x0 c!         ;r23=!x3
or r19,r24            ;r23=!x3+x2
or r22,r24           ;r23=(!x3+x2)*x1
and r19,r22            ;r23=((!x3+x2)*x1)+!x0

ldi r27,0b00000101    ;counter =5
rcall loopv           ;shift 5 bits to words left i.e 13 th pin
out PORTB,r19         ; The output is taken at 13 th pin of arduino and it is given to seven segmment display.`

rjmp main


Start:
rjmp Start

loopa:	lsr r18			;right shift
		dec r20			;counter --
	    	brne	loopa	;if counter != 0
		ret
				    	
loopb:	lsr r19			;right shift
		dec r21			;counter --
		brne	loopb	;if counter != 0
		ret
loopc:	lsr r22			;right shift
		dec r16			;counter --
		brne	loopc	;if counter != 0
		ret
loopv:	lsl r19			;leftshift shift
		dec r27		;counter --
		brne	loopv	;if counter !
		ret
