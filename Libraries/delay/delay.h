/*---------------------------------------------------------------------------
DELAY.H

Header file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: Header file for 16x2 LCD Display operating in 8-bit mode.
---------------------------------------------------------------------------*/

#ifndef __DELAY_H__
#define __DELAY_H__

// enable delay functions
#define EN_SMALL_DEL 0
#define EN_MILLI_DEL 1
#define EN_SECND_DEL 0

// Prototype Declarations
extern void smallDelay(void);
extern void delayMS(unsigned int);
extern void delayS(unsigned int);


#endif
