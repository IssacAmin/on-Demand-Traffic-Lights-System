/*
 * Button.h
 *
 * Created: 9/8/2022 3:37:13 PM
 *  Author: Issac
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO DRIVER/DIO.h"

void button_init(uint8_t port_char, uint8_t pin_number);
void button_read(uint8_t port_char, uint8_t pin_number, uint8_t *value);


#endif /* BUTTON_H_ */