/*
 * CFile1.c
 *
 * Created: 9/8/2022 1:50:54 PM
 *  Author: Issac
 */ 

#include "DIO.h"
#include "../REGISTER DRIVER/registers.h"
#include <stdint.h>


void dio_init(char port_char, uint8_t Direction, uint8_t pin_number)
{
	//checking which port by switch case structure then setting the direction bit according to the user input.
	switch(port_char)
	{
		case 'A':
		DDRA |= (Direction<<pin_number);
		break;
		case 'B':
		DDRB |= (Direction<<pin_number);
		break;
		case 'C':
		DDRC |= (Direction<<pin_number);
		break;
		case 'D':
		DDRD |= (Direction<<pin_number);
		break;
		default:
		break;
	}
}


void dio_high(char port_char, uint8_t pin_number)
{
	//checking which port by switch case structure then setting the required bit to high according to the user input.
	switch(port_char)
	{
		case 'A':
		PORTA |= (HIGH<<pin_number);
		break;
		case 'B':
		PORTB |= (HIGH<<pin_number);
		break;
		case 'C':
		PORTC |= (HIGH<<pin_number);
		break;
		case 'D':
		PORTD |= (HIGH<<pin_number);
		break;
		default:
		break;
	}
	
}


void dio_low(char port_char, uint8_t pin_number)
{
	//checking which port by switch case structure then setting the required bit to low according to the user input.
	switch(port_char)
	{
		case 'A':
		PORTA &= ~(1<<pin_number);
		break;
		case 'B':
		PORTB &= ~(1<<pin_number);
		break;
		case 'C':
		PORTC &= ~(1<<pin_number);
		break;
		case 'D':
		PORTD &= ~(1<<pin_number);
		break;
		default:
		break;
	}
}


void dio_read(char port_char, uint8_t pin_number, uint8_t *value)
{
	//checking which port by switch case structure then storing the required bit to a variable by reference according to the user input.
	switch(port_char)
	{
		case 'A':
		*value = (PORTA & (1<<pin_number))>>pin_number;
		break;
		case 'B':
		*value = (PORTB & (1<<pin_number))>>pin_number;
		break;
		case 'C':
		*value = (PORTC & (1<<pin_number))>>pin_number;
		break;
		case 'D':
		*value = (PORTD & (1<<pin_number))>>pin_number;
		break;
		default:
		break;
	}
	
}


void dio_toggle(char port_char, uint8_t pin_number)
{
	//checking which port by switch case structure then toggling the required bit according to the user input.
	switch(port_char)
	{
		case 'A':
		PORTA ^= (1<<pin_number);
		break;
		case 'B':
		PORTB ^= (1<<pin_number);
		break;
		case 'C':
		PORTC ^= (1<<pin_number);
		break;
		case 'D':
		PORTD ^= (1<<pin_number);
		break;
		default:
		break;
	}
}