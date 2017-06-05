#include "main.h"

void display(void)
{
	/* Potentiometer */
	data = adc() >> 2;
	for (k = 15; k >= 13; k--)
	{
		/* convert the result into ASCII  */
		counter[k] = data % 10 + '0';
		data = data / 10;
	}
	/* checking Event ON or OF  */
	if (counter[13] == '0' && counter[14] == '0' && counter[15] == '0')
		counter[9] = 'F';
	else
		counter[9] = 'O';
	if (key == '8')	
	{
		strcpy(log_count[j_idx], counter);
		puts(line1_home, "  ERROR OCCURED ");
		puts(line2_home, log_count[j_idx]);
		j_idx++;
		delay(2500);
	}

	puts(line1_home, message);
	puts(line2_home, counter);	
}
