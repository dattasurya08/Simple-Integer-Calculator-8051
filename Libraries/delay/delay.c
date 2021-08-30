/*---------------------------------------------------------------------------
DELAY.C

C Library file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: C Library file for Delay Subroutines of different ranges.
---------------------------------------------------------------------------*/

#include "delay.h"

#if(EN_SMALL_DEL == 1)
/* 100us delay */
void smallDelay(void)
{
    char sd;
	  for(sd = 0; sd < 125; sd++);
}
#endif

#if((EN_MILLI_DEL == 1)|(EN_SECND_DEL == 1))
/* 1ms variable delay */
void delayMS(unsigned int Tms)
{
    unsigned int t, s;
	  for(t = 0; t < Tms; t++)
	      for(s = 0; s < 1275; s++);
}
#endif

#if(EN_SECND_DEL == 1)
/* 1s variable delay */
void delayS(unsigned int Ts)
{
    unsigned int T;
	  for(T = 0; T < Ts; T++)
	      delayMS(1000);
}
#endif
