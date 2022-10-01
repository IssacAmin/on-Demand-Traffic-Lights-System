/*
 * Button.c
 *
 * Created: 9/8/2022 3:37:30 PM
 *  Author: Issac
 */ 

#include "Button.h"


void button_init(uint8_t port_char, uint8_t pin_number)
{
	// setting the direction of required pin to input via DIO driver.
	dio_init(port_char, INPUT, pin_number);
}
void button_read(uint8_t port_char, uint8_t pin_number, uint8_t *value)
{
	// reading the required pin and storing the result to a variable by reference via DIO driver.
	dio_read(port_char, pin_number, value);
}


