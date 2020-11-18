#include "EscaleraMecanicaRequired.h"
#include "board.h"

#define LED1      3
#define LED2      4
#define LED3      5

void escaleraMecanicaIface_opSubir(const EscaleraMecanica* handle, const sc_boolean Action, const sc_boolean Status){
	Board_LED_Set(LED1, false);
	Board_LED_Set(LED2, true);
	Board_LED_Set(LED3, false);
}

void escaleraMecanicaIface_opBajar(const EscaleraMecanica* handle, const sc_boolean Action, const sc_boolean Status){
	Board_LED_Set(LED1, true);
	Board_LED_Set(LED2, false);
	Board_LED_Set(LED3, false);
}

void escaleraMecanicaIface_opStop(const EscaleraMecanica* handle, const sc_boolean Action, const sc_boolean Status){
	Board_LED_Set(LED1, true);
	Board_LED_Set(LED2, true);
	Board_LED_Set(LED3, true);
}

void escaleraMecanicaIface_opLuzRoja(const EscaleraMecanica* handle, const sc_boolean Action, const sc_boolean State){

}

void escaleraMecanicaIface_opLuzVerde(const EscaleraMecanica* handle, const sc_boolean Action, const sc_boolean State){

}


