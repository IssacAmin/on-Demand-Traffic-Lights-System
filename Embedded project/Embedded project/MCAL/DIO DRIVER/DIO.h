/*
 * DIO.h
 *
 * Created: 9/8/2022 1:50:45 PM
 *  Author: Issac
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

//defines for readability.
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define PTA 'A'
#define PTB 'B'
#define PTC 'C'
#define PTD 'D'



//DIO Driver API prototypes.
void dio_init(char port_char, uint8_t Direction, uint8_t pin_number);
void dio_high(char port_char, uint8_t pin_number);
void dio_low(char port_char, uint8_t pin_number);
void dio_read(char port_char , uint8_t pin_number, uint8_t *value);
void dio_toggle(char port_char, uint8_t pin_number);


#endif /* DIO_H_ */