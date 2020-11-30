#ifndef _GPIO_H_
#define _GPIO_H_

#include "board.h"


typedef bool bool_t;

typedef enum{
   GPIO_I,
   GPIO_O,
   GPIO_I_PULLUP,
   GPIO_I_PULLDOWN,
   GPIO_I_REPEATER
} gpioInit_t;


typedef struct {
	bool_t scuPort;
	bool_t scuPin;
	bool_t gpioPort;
	bool_t gpioPin;
	bool_t func;
} gpioPinConfig_t;


typedef enum{
	LED1,
	LED2,
	LED3,
	LED0_R,
	LED0_G,
	LED0_B,
	TEC1,
	TEC2,
	TEC3,
	TEC4
} gpioMap_t;

void gpioInit( gpioMap_t pin, gpioInit_t conf );

void gpioWrite( gpioMap_t pin, bool_t value );

bool_t gpioRead( gpioMap_t pin);

#endif
