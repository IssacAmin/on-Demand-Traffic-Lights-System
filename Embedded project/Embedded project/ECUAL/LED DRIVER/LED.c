/*
 * CFile1.c
 *
 * Created: 9/8/2022 1:50:22 PM
 *  Author: Issac
 */ 

#include "LED.h"
#include "../../MCAL/TIMER DRIVER/Timer.h"
#define PRESCALER 1024


void led_init(uint8_t port_char, uint8_t pin_number)
{
	// setting the direction of required pin to OUTPUT via DIO driver.
	dio_init(port_char, OUTPUT, pin_number);
}

void led_on(uint8_t port_char, uint8_t pin_number)
{
	// setting the value of required pin to HIGH via DIO driver.
	dio_high(port_char, pin_number);
}
void led_off(uint8_t port_char, uint8_t pin_number)
{
	// setting the value of required pin to LOW via DIO driver.
	dio_low(port_char, pin_number);
}
void led_toggle(uint8_t port_char, uint8_t pin_number)
{
	// toggling the value of required pin via DIO driver.
	dio_toggle(port_char,pin_number);
}

void led_blinkSec(BLINK_MODE blinkMode)
{
	if(blinkMode == BOTH)
			{	

					led_on(PTA, 1);
					led_on(PTB, 1);
					delayTimeInSec(0.5, PRESCALER);
					led_off(PTA,1);
					led_off(PTB,1);
					delayTimeInSec(0.5,PRESCALER);

			}
			else
			{
	
					led_on(PTA, 1);
					delayTimeInSec(0.5, PRESCALER);
					led_off(PTA,1);
					delayTimeInSec(0.5,PRESCALER);
								
				
			}
}
