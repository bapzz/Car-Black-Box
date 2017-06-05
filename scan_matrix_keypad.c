#include "main.h"

unsigned char scan_matrix_keypad(void)
{
	unsigned char i, j;

	// for the rows of matrix key pad
	for (i = 0; i < 3; i++)
	{
		// setting 1 on the rows one by one
		//setting RB 5, 6, 7;
		PORTB = (PORTB & 0x1F) | (~(0x20 << i) & 0xE0);
		// for checking column 
		for (j = 0; j < 4; j++)
		{
			// Accessing RB 1, 2, 3, 4;
			if (!(PORTB & (1 << (j + 1))))
			{
				return 48 +  (((i * 4) + j) + 1);
			}
		}
	}
	/*if (p_flag == 0)
		return key;
	else if(p_flag == 1)*/
		return 0xFF;
}
