#include "HornoMicroondasRequired.h"
#include "board.h"

#define LED1      3
#define LED2      4
#define LED3      5

void hornoMicroondasIface_opSetModo(const HornoMicroondas* handle, const sc_integer Number){
	switch (Number){
		case 0:
			Board_LED_Set(LED1, true);
			Board_LED_Set(LED2, false);
			Board_LED_Set(LED3, false);
			break;
		case 1:
			Board_LED_Set(LED1, false);
			Board_LED_Set(LED2, true);
			Board_LED_Set(LED3, false);
			break;
		case 2:
			Board_LED_Set(LED1, false);
			Board_LED_Set(LED2, false);
			Board_LED_Set(LED3, true);
			break;
		default:
			Board_LED_Set(LED1, false);
			Board_LED_Set(LED2, false);
			Board_LED_Set(LED3, false);
			break;
	}

}

void hornoMicroondasIface_opCocinar(const HornoMicroondas* handle, const sc_integer Number){
	Board_LED_Set(LED1, true);
	Board_LED_Set(LED2, true);
	Board_LED_Set(LED3, true);
}

void hornoMicroondasIface_opIdle(const HornoMicroondas* handle){
	Board_LED_Set(LED1, false);
	Board_LED_Set(LED2, false);
	Board_LED_Set(LED3, false);
}

