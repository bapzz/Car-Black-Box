/*
   * Author : Biswajeet Sahoo
   * Date : 16-05-2017 
*/

#include "main.h"

void init_config()
{
	init_clcd_config();
	init_ADC_config();
	init_timer0_config();
	init_mkp_config();
}

void main()
{
	init_config();
#if 0
	/*  init EEPROM to 0 */
	unsigned char *ptr = 0x00;
	while ((*ptr++) != 0xFF)
		write_internal_eeprom(*ptr,'0');
#else
	/*  if EEPROM have data copy it */
	if (read_internal_eeprom(0x00) != '0')
	{
		puts(line1_home," READING EEPROM ");
		delay(3000);
		char str[17];
		E_count = 0x00;
		log_itr = (read_internal_eeprom(0x00) - '0');
		for (i = 0;i < log_itr; i++ )
		{
			for (j = 0;j < 16; j++ )
				str[j] = read_internal_eeprom(E_count += 1);
			str[16] = '\0';
			strcpy(log_count[i],str);
		}
	}


	while(1)
	{
		/* DEFAULT SCREEN */
		if(p_flag == 0)
			display();
		/* Scaning the key */
		key = scan_matrix_keypad();
		/* Entering To Password */
		if ((key == '5') && (pw_flag == 1))
		{
			password_check();
			/* if password correct */
			if (correct_p)
			{
				if ((key == '5') && (pw_flag == 0))
				{
					main_menu();
				}

			}
		}
		else if (key == '1')/* gear up */
		{
			delay(1000);
			if (counter[11] < '5')
			{
				gear++;
				counter[11]++;
			}
		}
		else if (key == '2')/* gear down */
		{
			delay(1000);
			if (counter [11] > '0')
			{
				counter[11]--;
				gear--;
			}
		}
		else if (key == '3')/* Collision */
		{
			store_log();
		}
		/* returning to default screen */
		else if (main_menu_flag)
		{
			p_flag = 0;
		}

		if (!E_got)
		{
			E_got = 1;
			/*  speed limit defination */
			if (((gear == 1) && (data > 30)) || ((gear == 2) && (data < 10 || data > 50)) || ((gear == 3) && (data < 20 || data > 80)) || ((gear == 4) && (data < 30 && data > 120)) || ((gear == 5) && (data < 50 || data > 220)))
			{
				store_log();
			}
		}

	}
#endif
}

