;POS expression operations
;output displayed using 7447 IC

.include "/sdcard/Download/codes/assignment1/assembly/m328Pdef.inc"


ldi r16, 0b00111100 ;identifying output pins 2
out DDRD,r16		;declaring pins as output



ldi r16,0b00000001	;initializing a
ldi r17,0b00000000	;initializing b
ldi r18,0b00000001	;initializing c


ldi r23,0b00000001
eor r23,r18       ;c!
OR r17,r23       ;b+c!
OR r16,r23        ;a+c!
AND r16,r17       ;(b+c!)&&(a+c!)


;following code is for displaying output
;shifting LSB in r16 to 2nd position
ldi r20, 0b00000010	;counter = 2

rcall loopw		;calling the loopw routine

out PORTD,r16		;writing output to pins 2,3,4


Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r16 	;left shift
	dec r20			;counter --
	brne loopw	;if counter != 0
	ret
