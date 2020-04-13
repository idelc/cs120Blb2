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
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char tmpSum = 0x00;
	while (1) {
		tmpA = PINA;
        	tmpB = PINB;
		tmpC = PINC;
		tmpD = 0x00;
		tmpSum = tmpA + tmpB + tmpC;
		tmpD = tmpSum;
		if(tmpSum > 140){
			tmpD = tmpD | 0x01;
		}
		else {
			tmpD = tmpD & 0xFE;
		}
		if(abs(tmpA - tmpC) > 80){
			tmpD = tmpD | 0x02;
		}
		else{
			tmpD = tmpD & 0xFD;
		}
		PORTD = tmpD; 			
	}
	return 1;
}
