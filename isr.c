#include "main.h"

extern unsigned short count;

void interrupt isr (void)
{
	unsigned short p,q;
	
	if (TMR0IF)
	{
		TMR0IF = 0;
		count++;
		E_time++;
	}
	if (count == 76)
	{
		//increments the last value
		counter[7]++;
		//checks for the every digit
		for (i = 7; i >= 0; i--)
		{
			/* for incrementing the timer 0-9 */
			if (i == 4 || i == 7)
			{
				if (counter[i] > '9')
				{
					counter[i] = '0';
					counter[i - 1]++;
				}
			}
			/* For incrementing the timer 0-5 */
			else if (i == 3 || i == 6)
			{
				if (counter[i] > '5')
				{
					counter[i] = '0';
					counter[i - 2]++;
				}
			}
			/* for HH */
			else if (i == 1)
			{
				/* FOR 24hrs */
				if (counter[i - 1] == '2')
				{
					if (counter[i] > '3')
					{
						counter[i] = '0';
						counter[i - 1]++;
					}
				}
				else
				{
					if (counter[i] > '9')
					{
						counter[i] = '0';
						counter[i - 1]++;
					}
				}
			}
			/* make 00 if gets 24 */
			else if (i == 0)
			{
				if (counter[i] > '2')
				{
					counter[i] = '0';
				}
			}
		}
		count = 0;
	}

	if (E_time == 760)
	{
		write_internal_eeprom(0x00,log_itr%10+'0');
		E_count = 0x00;

		for(p = 0;p < log_itr; p++)
		{
			for(q = 0;q < 16; q++)
				write_internal_eeprom(E_count += 1,log_count[p][q]);
		}
		E_got = 0;
		E_time = 0;
	}

}
