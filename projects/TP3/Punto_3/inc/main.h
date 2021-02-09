
#ifndef _MAIN_H_
#define _MAIN_H_

#include "sapi.h"


typedef enum{
   BUTTON_STATE_ON,
   BUTTON_STATE_OFF,
   BUTTON_STATE_FALLING,
   BUTTON_STATE_RISING
} buttonState_t;

typedef struct {
	gpioMap_t button;
	buttonState_t button_state;
}button_t;

void initButton(button_t* t, gpioMap_t ID);


void buttonUpdate(button_t* t);

void buttonRaised(button_t* t);

void buttonFalled(button_t* t);
#endif