/*
 * Applicaion.h
 *
 * Created: 9/8/2022 1:49:31 PM
 *  Author: Issac
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

typedef enum LIGHTSTATE 
{
	RED_LIGHT, YELLOW_LIGHT, GREEN_LIGHT
	}LIGHTSTATE_T;

typedef enum bool
{
	false, true
	} bool; 
	
	
void AppStart(void);
void App_init(void);
void normal_mode(void);
void pedestrian_mode(LIGHTSTATE_T* state);




#endif /* INCFILE1_H_ */