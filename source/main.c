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
        DDRB = 0x00; PORTB = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char bitA = 0x00;
	unsigned char bitB = 0x00;
	unsigned char totalC = 0x00;
	unsigned char i = 0x00;
    while (1) {
	bitA = PINA;
	bitB = PINB;
	totalC = 0x00;
	for(i = 0; i < 8; ++i) {
		totalC = totalC + ((bitA >> i) & 0x01);
	}
	for(i = 0; i < 8; ++i) {
                totalC = totalC + ((bitB >> i) & 0x01);
        }
	PORTC = totalC;

    }
    return 0;
}
