#ifndef SCAN_MATRIX_KEYPAD_H
#define SCAN_MATRIX_KEYPAD_H

#define ROW1 PORTBbits.RB5
#define ROW2 PORTBbits.RB6
#define ROW3 PORTBbits.RB7

#define	COL1 PORTBbits.RB1
#define COL2 PORTBbits.RB2
#define COL3 PORTBbits.RB3
#define COL4 PORTBbits.RB4

unsigned char scan_matrix_keypad(void);

#endif

