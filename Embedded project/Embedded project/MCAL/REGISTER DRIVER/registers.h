/*
 * registers.h
 *
 * Created: 9/12/2022 2:59:06 AM
 *  Author: Issac
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#define SREG *((volatile uint8_t*)0x5F)
#define PORTA *((volatile uint8_t*)0x3B)
#define PORTB *((volatile uint8_t*)0x38)
#define PORTC *((volatile uint8_t*)0x35)
#define PORTD *((volatile uint8_t*)0x32)
#define DDRA *((volatile uint8_t*)0x3A)
#define DDRB *((volatile uint8_t*)0x37)
#define DDRC *((volatile uint8_t*)0x34)
#define DDRD *((volatile uint8_t*)0x31)



#endif /* INCFILE1_H_ */