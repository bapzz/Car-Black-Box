#include "main.h"

void write_internal_eeprom(unsigned char address, unsigned char data)
{
	/* write the address */
	EEADR = address;

	/* Write the data */
	EEDATA = data;

	/* Point to data memory */
	EECON1bits.EEPGD = 0;
	
	/* Access data EEPROM memory */
	EECON1bits.CFGS = 0;
	
	/* Data write Enable Bit */
	EECON1bits.WREN = 1;

	/* Global Interrupt Disable */
	GIE = 0;

	/* Write Protection Sequence */
	EECON2 = 0x55;
	EECON2 = 0xAA;
	
	/* Initiate Write */
	EECON1bits.WR = 1;

	/* Global interrupt enable */
	GIE = 1;
	
	/* Wait till write is complete */
	while (!PIR2bits.EEIF);
	
	/* Disable the Flag*/
	PIR2bits.EEIF = 0;
}

unsigned char read_internal_eeprom(unsigned char address)
{
	/* Write the address from where data has to be read */
	EEADR = address;

	/* Inhibits write cycle to flash program/data EEPROM */
	EECON1bits.WREN = 0;

	/* Point to data memory */
	EECON1bits.EEPGD = 0;
	
	/* Point to data memory */
	EECON1bits.CFGS = 0;
	
	/* Access data EEPROM memory */
	EECON1bits.RD = 1;

	/* data available in EEDATA register */
	return EEDATA;

}
