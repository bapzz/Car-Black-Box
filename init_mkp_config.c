#include "main.h"

void init_mkp_config(void)
{
	//Config RB7, RB6, RB5 as an output pins
	//Config RB4, RB3, RB2, RB1 as an input pins 
	//Note: Don't modify the LSB
	TRISB = (TRISB & 0x01) | 0x1E;

	//Enable internal pull-ups for the PORTB
	RBPU = 0;

	//Make all the PORTB as an digital port
	ADCON1 = 0x0E;
}


