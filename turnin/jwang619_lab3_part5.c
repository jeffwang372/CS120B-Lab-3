/*	Author: jwang619
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0x06; PORTB = 0x01;
    /* Insert your solution below */
	unsigned char tempD = 0x00;
	unsigned char tempB = 0x00;
	unsigned short totalInput = 0x0000;
	unsigned char outB = 0x00;
	
    while (1) {
	outB = 0x00;
	tempD = PIND;
	tempB = PINB;
	tempD = tempD << 1;
	totalInput = tempD;

	if(tempB == 0x01) {
		++totalInput;
	}
	if(totalInput >= 70) {
		outB = outB | 0x02;
	}
	if(totalInput > 5 && totalInput < 70) {
		outB = outB | 0x04;
	}
	if(totalInput <= 5) {
		outB = 0x00;
	}
	PORTB = outB;	
	

    }
    return 0;
}
