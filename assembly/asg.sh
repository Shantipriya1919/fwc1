
#!/bin/bash

#cd /sdcard/Download/codes/assignment1/ide/codes
#pio run
##pio run -t upload
#
#
#cd /sdcard/Download/codes/assignment1/ide/docs
#pdf latex asg_1.tex
#termux-open asg_1.pdf

cd /sdcard/Download/codes/assignment1/assembly/codes
avra asg1.asm
##avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -U flash:w:ass_2.hex
#
cd /sdcard/Download/codes/assignment1/assembly/docs
pdflatex asg1.tex
termux-open asg1.pdf

#cd /sdcard/Download/codes/assignment1/avr-gcc/codes
#make

#cd /sdcard/Download/codes/assignment1/avr-gcc/docs
#pdflatex asg1.tex
#termux-open asg1.pdf
