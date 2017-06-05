#include "main.h"

void write_lcd(unsigned char data, unsigned char mode)
{
	PORTD = data;
	RS = mode;
	RW = 0;
	lcd_strobe;
}

void is_busy(void)
{
	//config RD7  as an input port
	TRISDbits.RD7 = 1;

	RS = 0;
	RW = 1;

	do 
	{
		lcd_strobe;
	}while (busy);

	//config PORTD as an o/p
	TRISDbits.RD7 = 0;
}

void puts(unsigned char location, const char *ptr)
{
	write_lcd(location, CMD_MODE);

	//wait if lcd is busy
	is_busy();

	while(*ptr)
	{
		//wait if lcd is busy
		is_busy();
		write_lcd(*ptr++, DATA_MODE);
	}
}

void putchar(unsigned char location, unsigned char ch)
{
	write_lcd(location, DATA_MODE);

	//wait if lcd is busy
	is_busy();

	write_lcd(ch, DATA_MODE);



}
