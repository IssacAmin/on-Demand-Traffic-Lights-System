/*
 * Timer.h
 *
 * Created: 9/8/2022 3:41:05 PM
 *  Author: Issac
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../MCAL/DIO DRIVER/DIO.h"
#include <avr/io.h>
//timer driver prototypes
void delayTimeInSec(float delay_time, int prescaler);



#endif /* TIMER_H_ */