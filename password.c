/*
   * Author : Biswajeet Sahoo
   * Date : 16-05-2017 
*/

#include "main.h"

int password_check(void)
{
	char hiden_pass[] = "                ";	
	/* clear display */	
	clear_display;
	/* Password display */
	puts(line1_home, passwrd);
	puts(line2_home, "                ");
	j = 0;
	/* scans untill password entered in BINARY */
	while (j <= 7)
	{	
		p_flag = 1;
		p_key = scan_matrix_keypad();
		/* For 0 */
		if (p_key == '1')
		{
			e_passwd[j] = '0';
			hiden_pass[j] = '*';
			display_blink;
			j++;
		}
		/* for 1 */
		else if(p_key == '2')
		{
			e_passwd[j] = '1';
			hiden_pass[j] = '*';
			display_blink;
			j++;
		}
		/* deleting wrong password */
		if(p_key == '4')
		{
			e_passwd[--j] = ' ';
		}
		/* returning back to home screen */
		if(p_key == '9')
			return main_menu_flag;
		puts(line2_home,e_passwd);
		//puts(line2_home,hiden_pass);
		write_lcd(0xC0+j, CMD_MODE);	
		delay(1000);

	}
	/* comparing engtered password for validation */
	if (!strcmp(e_passwd,o_passwd))
		pw_flag = 0;	/* password  matches */
	else
		pw_flag = 1;	/* password matches */

	/* if password matched */
	if (pw_flag == 0)
	{
		puts(line2_home, c_passwrd);
		correct_p = 1;
		for (j = 0; j <= 7; j++)
		{
			e_passwd[j] = ' ';
			hiden_pass[j] = ' ';
		}
	}
	/* if password worng ask again */
	else if (pw_flag == 1)
	{
		puts(line2_home, w_passwrd);
		p_flag = 0;
		delay(2500);
		for (j = 0; j <= 7; j++)
		{
			e_passwd[j] = ' ';
			hiden_pass[j] = ' ';
		}
	}
}

int main_menu(void)
{
	/* LOG and Time Menu */
	clear_display;
	puts(line1_home, "* VIEW LOG");
	puts(line2_home, "  SET TIME");

	while (1)
	{
		mm_key = scan_matrix_keypad();
		/* toggleing between menu */
		if (mm_key == '1')
		{
			tmm_flag = !tmm_flag;

			if (tmm_flag == 0)
			{
				puts(line1_home, v_log);
				puts(line2_home, "  SET TIME");
			}
			if (tmm_flag == 1)
			{
				puts(line1_home, "  VIEW LOG");
				puts(line2_home, s_time);
			}
			delay(500);
		}
		/* selecting the Menu */
		if (mm_key == '2')
			set_time_func();
		/* returning to Main screen */
		if (mm_key == '9')
		{
			pw_flag = 1;
			return main_menu_flag;
		}
	}
}

int set_time_func(void)
{
	/* Viewing logs */
	if ((mm_key == '2') && (tmm_flag == 0))
	{
		clear_display;
		char i_idx = '1';
		puts(line1_home, view_logs);
		k = 0;

		while (1)
		{
			delay(700);
			key = scan_matrix_keypad();
			/* display log */		
			if ((key == '1') && (k < log_itr))
				k++;
			else if ((key == '2') && (k > 0))
				k--;
			if (key == '9')
				return main_menu_flag;

			puts(line2_home, log_count[k]);
		}
	}


	/* Editing time */
	if ((mm_key == '2') && (tmm_flag == 1))
	{

		clear_display;
		char temp_time[] = "00.00.00";
		/* gets the present time */
		for (l = 0; l < 8 ; l++)
			temp_time[l] = counter[l];
		l = 0;
		puts(line1_home, set_time);
		/* changeing time */
		while (l < 8)
		{
			delay(600);
			tc_key = scan_matrix_keypad();
			/* incrementing time */
			if (tc_key == '1')
			{
				temp_time[l]++;
				if (temp_time[l]== ':')
					temp_time[l] = '0';
				display_blink;
			}
			/* decrementing */
			else if (tc_key == '2')
			{					
				temp_time[l]--;
				if (temp_time[l] == 47)
					temp_time[l] = '9';
				display_blink;					
			}
			/* shifting position */
			else if (tc_key == '4')
			{
				l++;
				if ((l == 2)||(l == 5))
					l++;
				display_blink;
			}				
			puts(line2_home,temp_time);
			write_lcd(0xC0+l, CMD_MODE);	
		}
		/* saving edited time to current time */
		for (l = 0; l < 8 ; l++)
			counter[l] = temp_time[l];

	}

}

int store_log()
{
	int p;
	/* capturing the error logs */
	if (log_itr == 9)
		for(p = 0; p < 9; p++)
		{
			strcpy(log_count[p],log_count[p+1]);
			//log_count[p][0] = ((p+1)% 10) + '0';
		}

	strcpy(log_count[log_itr],counter);
	puts(line1_home," ERROR OCCURRED  ");
	puts(line2_home,log_count[log_itr]);
	if(log_itr < 9)
		log_itr++;
	delay(2500);
}
