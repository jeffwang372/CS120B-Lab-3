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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
        DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char upperA = 0x00;
	unsigned char lowerA = 0x00;
	
    while (1) {
	PORTB = 0x00;
	PORTC = 0x00;
	
	upperA = PINA & 0xF0;
	lowerA = PINA & 0x0F;
	
	upperA = upperA >> 4;
	lowerA = lowerA << 4;
	
	PORTB = PORTB & 0xF0;
	PORTC = PORTC & 0x0F;

	PORTB = PORTB | upperA;
	PORTC = PORTC | lowerA;
	

    }
    return 0;
}
