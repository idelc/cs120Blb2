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
        DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
        unsigned char tmpA = 0x00;
        unsigned char tmpC = 0x00;
        while (1) {
                tmpA = PINA;
                tmpC = 0x00;
                if((tmpA & 0x01) == 0x01){
                        tmpC = tmpC + 1;
                }
                if((tmpA & 0x02) == 0x02){
                        tmpC = tmpC + 1;
                }
                if((tmpA & 0x04) == 0x04){
                        tmpC = tmpC + 1;
                }
                if((tmpA & 0x08) == 0x08){
                        tmpC = tmpC + 1;
                }
                PORTC = 4-tmpC;
		if(tmpC == 4){
			PORTC = PORTC | 0x80;
		}

        }
        return 1;
}
