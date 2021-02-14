
#ifndef _MAIN_H_
#define _MAIN_H_

#include "sapi.h"

#define BUTTON1 myTEC1

#define BUTTON2 myTEC2

#define BUTTON3 myTEC3

#define BUTTON4 myTEC4

typedef enum{
   BUTTON_STATE_ON,
   BUTTON_STATE_OFF,
   BUTTON_STATE_FALLING,
   BUTTON_STATE_RISING
} buttonState_t;

typedef struct {
	gpioMap_t button;
	buttonState_t button_state;
	char* name;
}myButton_t;

void initButton(myButton_t* t, gpioMap_t ID);


void buttonUpdate(myButton_t* t);

void buttonRaised(myButton_t* t);

void buttonFalled(myButton_t* t);
#endif
