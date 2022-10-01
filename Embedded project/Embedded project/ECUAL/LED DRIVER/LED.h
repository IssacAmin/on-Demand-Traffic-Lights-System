/*
 * LED.h
 *
 * Created: 9/8/2022 1:50:13 PM
 *  Author: Issac
 */ 
#include "../../MCAL/DIO DRIVER/DIO.h"


#ifndef LED_H_
#define LED_H_

typedef enum BLINK_MODE
{
	CARS_ONLY, BOTH	
} BLINK_MODE;

//prototypes for led driver

void led_init(uint8_t port_char, uint8_t pin_number);
void led_on(uint8_t port_char, uint8_t pin_number);
void led_off(uint8_t port_char, uint8_t pin_number);
void led_toggle(uint8_t port_char, uint8_t pin_number);
void led_blinkSec(BLINK_MODE blinkMode);


#endif /* LED_H_ */