#include "main.h"

void init_timer0_config(void)
{
	//config T0CON register, this reg controls the timer0
	//enable the timer0 module
	TMR0ON = 1;

	//timer0 is configured as an 8-bit timer
	T08BIT = 1;

	//select internal instruction cycle clock as a source
	T0CS = 0;

	//timer0 prescaler assignment bit
	PSA = 0;

	//select 1:256 prescalr
	T0PS2 = 1;
	T0PS1 = 1;
	T0PS0 = 1;

	//enable timer0 intrrupt
	TMR0IE = 1;

	//ENABLE peripheral interrupt
	//PEIE = 1;
	
	//enable global intrerrupt
	GIE = 1;

	//set timer0 intrrupt flag to 0
	TMR0IF = 0;
}
