#include "main.h"

void init_clcd_config(void)
{
	//for sending data port d as o/p
	TRISD = 0;

	//for sending control signal
	TRISC = 0;

	eight_bit_two_line_display;
	delay(250);

	display_on_cursor_on;
	delay(250);

	clear_display;
	delay(5);

	entry_mode;
	delay(5);
	
	display_blink;
	delay(1000);
}
