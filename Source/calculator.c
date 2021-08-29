/*---------------------------------------------------------------------------
CALCULATOR.C

C Source file for 80C51 Microcontroller.
Author(s): Sree Suryadatta M Vadhoolas (datta_surya08).
Description: C Source file for a Simple 16-bit Integer Calculator.
Components: 8051 board, 4x4 Keyboard (push-buttons + pullup resistors)
Simulation: Proteus Software (AT89C51RD2)
---------------------------------------------------------------------------*/

#include <reg51.h>
#include <delay.h>
#include <lcd8bit.h>
#include <keyboard4x4.h>

/* Check character is an operator {/, X, -, +} */
bit isOperator(unsigned char val)
{
    unsigned char x;
	for(x = 0; x < 4; x++)
	{
	    if(val == key[x][3])
		    return 1;
	}
	return 0;
}

/* Convert int answer to str for display */
void decTOhex(int dec, unsigned char* hex)
{
    unsigned char count = 0, j;
	unsigned char rem [8];
	bit neg = 0;
	if(dec < 0)
	{
	    neg = 1;
		dec = 0 - dec;
	}
	while(dec > 0)
	{
	    rem[count] = '0' + (dec%10);
		dec /= 10;
		count++;
	}
	if(neg)
	{
	    rem[count] = '-';
		count++;
	}
	for(j = 0; j < count; j++)
	{
	    hex[j] = rem[count - 1 - j];
	}
}

/* Display appropriate output/error */
void output(bit error, int answer)
{
	unsigned char hexans[8] = "0       ";
	if(error)
	{
	    lcdCMDorDISPLAY(command, LCD_CLR_DISP);
		if(answer == 0)
		{
		    lcdDisplayStr(0, 2, "SYNTAX ERROR");
		}
		else
		{
		    lcdDisplayStr(0, 3, "MATH ERROR");
		}
	}
	else
	{
		decTOhex(answer, hexans);
		lcdDisplayStr(1, 0, hexans);
	}
}

/* Convert str expression, validate, calculate answer */
void calculate(unsigned char* expression)
{
    bit op = 0, error = 0;
	unsigned char j, k, p = 0, q = 0;
	unsigned int x, b;
	unsigned int num[8];
	unsigned char oper[8];
	int ans = 0;

	num[0] = 0;
	for(j = 0; j < 16; j++)
	{
	    if(expression[j] == '=')
		{
		    if(op)
			{
			    error = 1;
				ans = 0;
				break;
			}
			break;
		}
		else if(isOperator(expression[j]))
		{
		    if(op)
			{
			    error = 1;
				ans = 0;
				break;
			}
			else
			{
			    oper[q] = expression[j];
				op = 1;
				q++;
			}
		}
		else
		{
		    if(op)
			{
			    p++;
				num[p] = 0;
				op = 0;
			}
			x = expression[j] - '0';
			num[p] = (10 * num[p]) + x;
		}
	}

	if(~error)
	{
	    ans = num[0];
		for(k = 0; k < q; k++)
		{
			b = num[k + 1];
			if(oper[k] == key[0][3])
			{
			    if(b == 0)
				{
				    error = 1;
					ans = 1;
					break;
				}
				else
				    ans /= b;
			}
			else if(oper[k] == key[1][3])
			    ans *= b;
			else if(oper[k] == key[2][3])
			    ans -= b;
			else if(oper[k] == key[3][3])
			    ans += b;
		}
	}
	output(error, ans);
}


/* Main Routine */
void main()
{
    bit calc = 1, done = 0;
	char i;
	char expn [16];

	// Initialize
	lcdInit();
	keyboardInit();

	lcdDisplayStr(0, 0, "SimpleCalculator");
	lcdDisplayStr(1, 4, "MCS-8051");
	delayMS(200);
	lcdCMDorDISPLAY(command, LCD_CLR_DISP);

	// LOOP
	while(1)
	{
	    // Get expression
		for(i = 0; i < 16;)
		{
		    if(keypressed())
			{
			    expn[i] = getkey();
				// Restart for new expression
				if(done)
				{
				    lcdCMDorDISPLAY(command, LCD_CLR_DISP);
					done = 0; 
				}
				// key[3][0] = 'C': CLEAR
				if(expn[i] == key[3][0])
				{
				    calc = 0;
					break;
				}
				// key[3][2] = '=': Calculate
				if(expn[i] == key[3][2])
				{
				    break;
				}
				lcdCMDorDISPLAY(display, expn[i]);
				i++;
			}
		}

		if(calc)
		{
		    // Calculate
			calculate(expn);
			done = 1;
		}
		else
		{
		    // CLEAR
			lcdCMDorDISPLAY(command, LCD_CLR_DISP);
			calc = 1;
		}
	}
}