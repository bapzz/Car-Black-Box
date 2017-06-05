/*
   * Author : Biswajeet Sahoo
   * Date : 16-05-2017 
*/

#ifndef main_h
#define main_h

#include <xc.h>
#include "init_clcd_config.h"
#include "delay.h"
#include "clcd.h"
#include "string.h"
#include "init_ADC_config.h"
#include "adc.h"
#include "display.h"
#include "init_timer0_config.h"
#include "scan_matrix_keypad.h"
#include "init_mkp_config.h"
#include "EEPROM.h"


unsigned short data, count, log_itr, E_count, E_time, gear = 0, E_got;
int k, i, j = 0, p_flag= 0, pw_flag = 1, l_flag = 0,correct_p, tmm_flag = 0, l = 0,main_menu_flag = 1, j_idx = 0;
unsigned char key, p_key, mm_key, tc_key;

char message[] = "  TIME   E G SPD";
char counter[] = "00.00.00 0 0 000";

char passwrd[] = " ENTER PASSWORD ";
char w_passwrd[] = "*WRONG*PASSWORD*";
char c_passwrd[] = "*CRECT*PASSWORD*";
char clrscr[] = "                ";
char e_passwd[] = "        ";
char o_passwd[] = "01101001";
char v_log[] = "* VIEW LOG";
char s_time[] = "* SET TIME";
char view_logs[] = "  TIME   E G SPD";
char set_time[] = "  SET TIME  ";
char log_count[10][17];



#endif
