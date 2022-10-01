/*
 * Interrupts.c
 *
 * Created: 9/8/2022 4:17:23 PM
 *  Author: Issac
 */ 

#include "interrupts.h"



void interrupt_init(void)
{
	//setting global interrupts I bit
	SREG |= (1<<7);
	//sense control for INT0 pin to logical change  sense
	MCUCR = 0x00;
	MCUCR |= (1<<ISC00) | (1 << ISC01);
	//enabling int 0 interrupt
	GICR |= (1<<INT0);
	
}

