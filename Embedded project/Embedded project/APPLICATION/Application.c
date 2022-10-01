/*
 * Application.c
 *
 * Created: 9/8/2022 1:49:50 PM
 *  Author: Issac
 */ 
#include "../ECUAL/LED DRIVER/LED.h"
#include "../ECUAL/BUTTON DRIVER/Button.h"
#include "../MCAL/TIMER DRIVER/Timer.h"
#include "Application.h"
#include "../MCAL/Interrupts/interrupts.h"

#define PRESCALER 1024
LIGHTSTATE_T state;
bool PED_mode;

int light_seq = 0; //A variable to control the light sequence

void normal_mode(void)
{
	for(light_seq = 0 ; light_seq < 4; light_seq++)
	{
		if(light_seq == 1 || light_seq == 3)
		{
			state = YELLOW_LIGHT;
			for(int j = 0; j < 5; j++)
			{
				if(PED_mode == true)
				{
					PED_mode = false;
					break;
				}
				led_blinkSec(CARS_ONLY);
			}
		}
		else
		{
			if(light_seq == 0)
				state = GREEN_LIGHT;
			else
				state = RED_LIGHT;
			led_on(PTA, light_seq);
			for(int j = 0; j < 5; j++)
			{
				if(PED_mode == true)
				{
					PED_mode = false;
					break;
				}
				delayTimeInSec(1, PRESCALER);
			}
			led_off(PTA, light_seq);
		}
	}	
}


void pedestrian_mode(LIGHTSTATE_T* state)
{
	switch(*state)
	{
		case RED_LIGHT:
			led_off(PTA, 2);
			led_on(PTB, 0);
			led_on(PTA, 2);
			delayTimeInSec(5, PRESCALER);
			led_off(PTB, 0);
			led_off(PTA, 2);
			
			for(int j = 0; j < 5; j++)
				led_blinkSec(BOTH);
			
			led_on(PTB, 2);
			led_on(PTA, 0);
			delayTimeInSec(5,PRESCALER);
			led_off(PTB, 2);
			led_off(PTA, 0);
			
			light_seq = 0;
			break;
		case YELLOW_LIGHT:
			
			for(int j = 0; j < 5; j++)
				led_blinkSec(BOTH);

			led_on(PTB, 0);
			led_on(PTA, 2);
			delayTimeInSec(5, PRESCALER);
			led_off(PTB,0);
			led_off(PTA, 2);
			for(int j = 0; j < 5; j++)
				led_blinkSec(BOTH);
			
			led_on(PTB, 2);
			led_on(PTA, 0);

			delayTimeInSec(5, PRESCALER);
			led_off(PTB, 2);
			led_off(PTA, 0);
			light_seq = 0;
			break;
		case GREEN_LIGHT:
			led_off(PTA, 0);
			for(int j = 0; j < 5; j++)
				led_blinkSec(BOTH);
			
			led_on(PTB, 0);
			led_on(PTA, 2);
			delayTimeInSec(5, PRESCALER);
			led_off(PTB, 0);
			led_off(PTA, 2);
			
			for(int j = 0; j < 5; j++)
				led_blinkSec(BOTH);
			
			led_on(PTB, 2);
			led_on(PTA, 0);
			delayTimeInSec(5, PRESCALER);
			led_off(PTB, 2);
			led_off(PTA, 0);
			
		break;
		default:
		//do nothing.
		break;
	}
}

void App_init(void)
{
	int j = 0;
	for(j = 0 ; j < 3; j++)
		led_init(PTA, j);
	for(j = 0 ; j < 3; j++)
		led_init(PTB, j);
	button_init(PTD, 2);
	interrupt_init();
}


void AppStart(void)
{
	
	while(1)
	{
		// it will run the normal mode indefinitely till an interrupt signal comes in.
			normal_mode();
	}
	

}

ISR(INT0_vect)
{
	if(PED_mode == false)
	{ 
		PED_mode = true;
		pedestrian_mode(&state);
	}
}
