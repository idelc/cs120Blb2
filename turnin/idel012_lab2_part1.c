/*	Author:Ivann De la Cruz Andrade idel012
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #2  Exercise #1
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
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	while (1) {
		tmpA = PORTA & 0x01;
        	tmpB = PORTA & 0x02;
		if((tmpA) && (!tmpB)){
			PORTB = PORTB | 0x01;
		}
		else {
			PORTB = PORTB & 0xFE;
		} 	
	}
	return 1;
}
