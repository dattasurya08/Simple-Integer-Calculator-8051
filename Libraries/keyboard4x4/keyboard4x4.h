/*---------------------------------------------------------------------------
KEYBOARD4X4.H

Header file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: Header file for 4x4 Keyboard interface with 8051.
---------------------------------------------------------------------------*/

#ifndef __KEYBOARD4X4_H__
#define __KEYBOARD4X4_H__

#include <reg51.h>
#include <delay.h>

// Keyboard Ports
#define rowPort P2
#define colPort P0

// Variable declarations
extern unsigned char row, col;
extern unsigned char key[4][4];

// Prototype Declarations
extern unsigned char getRow(void);
extern unsigned char getCol(void);
extern bit keypressed(void);
extern void keyboardInit(void);
extern unsigned char getkey(void);

#endif
