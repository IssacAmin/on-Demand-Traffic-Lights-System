/*
 * CFile1.c
 *
 * Created: 9/8/2022 3:41:43 PM
 *  Author: Issac
 */ 
#include "Timer.h"
#include <math.h>
#define CPU_FREQUENCY 1000000


void delayTimeInSec(float delay_time, int prescaler)
{
		//Normal Mode Timer by setting TCCR0 register
		TCCR0 = 0x00;
		//variables
		int overflows = 0, initial_value = 0;
		//calculate the required overflows and initial values of the counter with the appropriate prescaler that is entered by coder.
		float tick_time = ((float)prescaler / 1000000.0);
		overflows = ceil( (float)delay_time  / (256 * (float)tick_time ) );
		initial_value = ceil(256 - ((((float)delay_time / tick_time)) / overflows)); // storing these calculations in 2 variables by reference.
	int overflow_counter = 0; 
	//setting initial value of timer.
	TCNT0 = initial_value;
	
		//using the calculations done by the initialization function, implement a delay.
		//the timer will start counting at prescaler assignment.
		switch(prescaler)
		{
			case 8:
			TCCR0 |= (1<<CS01);
			break;
			case 64:
			TCCR0 |= (1<<CS01) | (1<<CS00);
			break;
			case 256:
			TCCR0 |= (1<<CS02);
			break;
			case  1024:
			TCCR0 |= (1<<CS02) | (1<<CS00);
			break;
			default:
			TCCR0 |= (1<<CS00);
			break;
		}
		while(overflow_counter < overflows)
		{
			//busy wait till the counter overflows
			while((TIFR & (1<<0)) == 0);
			//clearing the overflow flag 
			TIFR |= (1<<0);
			//resetting the initial value for next overflow
			TCNT0 = initial_value;
			//incrementing the overflow counter
			overflow_counter++;
		}
}


