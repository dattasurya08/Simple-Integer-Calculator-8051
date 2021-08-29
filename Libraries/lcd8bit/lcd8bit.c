/*---------------------------------------------------------------------------
LCD8BIT.C

C Library file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: C Library file for 16x2 LCD Display operating in 8-bit mode.
---------------------------------------------------------------------------*/

#include "lcd8bit.h"
#include <delay.h>

/* Subroutine for LCD command and Display Value
   c_or_d: command/display mode (0/1)
   value:  hex-command/displaycharacter
*/
void lcdCMDorDISPLAY(bit c_or_d, unsigned char value)
{
  lcdPort = value;
  rs = c_or_d;
  rw = 0;
  en = 1;
  delayMS(1);
  en = 0;
  delayMS(1);
}

/* LCD Initialize Subroutine */
void lcdInit(void)
{
    lcdCMDorDISPLAY(command, LCD_LIN2_5X7);
    lcdCMDorDISPLAY(command, LCD_DON_COFF);
    lcdCMDorDISPLAY(command, LCD_CLR_DISP);
    lcdCMDorDISPLAY(command, LCD_CURZ_INC);
    lcdCMDorDISPLAY(command, LCD_CURZ_0_0);
}

/* Subroutine to set Cursor to (row, col) */
void lcdSetCurz(bit row, unsigned char col)
{
    if(row)
	    lcdCMDorDISPLAY(command, (LCD_CURZ_1_0|col));
	else
	    lcdCMDorDISPLAY(command, (LCD_CURZ_0_0|col));
}

/* Subroutine to display a string starting from (row, col) */
void lcdDisplayStr(bit row,unsigned char col, unsigned char *val)
{
    unsigned char i;
	lcdSetCurz(row, col);
	for(i = 0; i < 16; i++)
	{
	    if(val[i])
		    lcdCMDorDISPLAY(display, val[i]);
		else
		    break;
	}
}
