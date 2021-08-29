/*---------------------------------------------------------------------------
KEYBOARD4X4.C

Header file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: Header file for 4x4 Keyboard interface with 8051.
---------------------------------------------------------------------------*/

#include "keyboard4x4.h"

/* row, column, keyboard matrix variables */
unsigned char row = 0, col = 0;
unsigned char key[4][4] = {{'1', '2', '3', '/'},
                           {'4', '5', '6', 'X'},
			   {'7', '8', '9', '-'},
			   {'C', '0', '=', '+'}};

/* Subroutine to get row value of pressed key */
unsigned char getRow(void)
{
    unsigned char curRow = 0, pval = 0x01;
    for(curRow = 0; curRow < 4; curRow++)
    {
        rowPort = ~pval;
	if((colPort & 0x0f) != 0x0f)
	{
	    rowPort = 0xff;
	    break;
	}
	else
	{
	    pval = (pval << 1);
	}   
    }
    return curRow;
}

/* Subroutine to get col value of pressed key */
unsigned char getCol(void)
{
    unsigned char curCol = 0, pval = 0x01;
    rowPort = 0x00;
    for(curCol = 0; curCol < 4; curCol++)
    {
        if((colPort & pval) == 0)
	{
	    rowPort = 0xff;
		break;
	}
	else
	{
	    pval = (pval << 1);
	}
    }
    return curCol;
}

/* Subroutine to determine a valid key press */
bit keypressed(void)
{
    rowPort = 0x00;
    if ((colPort & 0x0f) != 0x0f)
        delayMS(15);                    // Debounce delay
    return ((colPort & 0x0f) != 0x0f);
}

/* Keyboard Initialize Subroutine */
void keyboardInit(void)
{
    colPort = 0xff;
    rowPort = 0x00;
    delayMS(10);
    while(keypressed());                // Initial: no key pressed 
}

/* Subroutine to get key value when pressed */
unsigned char getkey(void)
{
    row = getRow();
    col = getCol();
    while(keypressed());                // wait till key released
    return key[row][col];
}
