/*---------------------------------------------------------------------------
LCD8BIT.H

Header file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (dattasurya08).
Description: Header file for 16x2 LCD Display operating in 8-bit mode.
---------------------------------------------------------------------------*/

#ifndef __LCD8BIT_H__
#define __LCD8BIT_H__

#include <reg51.h>

// Constants
#define command 0
#define display 1

// LCD Ports
#define lcdPort P1
#define lcdCTRL P3

// LCD control pins
sbit rs = lcdCTRL^0;
sbit rw = lcdCTRL^1;
sbit en = lcdCTRL^2;

// LCD commands
#define LCD_CLR_DISP 0x01
#define LCD_RET_HOME 0x02
#define LCD_CURZ_DEC 0x04
#define LCD_SHFT_D_R 0x05
#define LCD_CURZ_INC 0x06
#define LCD_SHFT_D_L 0x07
#define LCD_DOFF_COF 0x08
#define LCD_DOFF_CON 0x0A
#define LCD_DON_COFF 0x0C
#define LCD_DON_CBLK 0x0E
#define LCD_DON_CBL2 0x0F
#define LCD_SHFT_C_L 0x10
#define LCD_SHFT_C_R 0x14
#define LCD_SHFT_FDR 0x18
#define LCD_SHFT_FDL 0x1C
#define LCD_CURZ_0_0 0x80
#define LCD_CURZ_1_0 0xC0
#define LCD_LIN2_5X7 0x38

// Prototype Declarations
extern void lcdCMDorDISPLAY(bit, unsigned char);
extern void lcdInit(void);
extern void lcdSetCurz(bit, unsigned char);
extern void lcdDisplayStr(bit, unsigned char, unsigned char*);

#endif
