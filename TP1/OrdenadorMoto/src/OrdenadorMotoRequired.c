#include "OrdenadorMoto.h"

#define LED1      3
#define LED2      4
#define LED3      5

void ordenadorMotoIface_opCambiarPantalla(const OrdenadorMoto* handle, const sc_integer Pantalla){
	switch (Pantalla){
	case 0:
		Board_LED_Set(LED1, false);
		Board_LED_Set(LED2, false);
		Board_LED_Set(LED3, false);
		break;
	case 1:
		Board_LED_Set(LED1, true);
		Board_LED_Set(LED2, false);
		Board_LED_Set(LED3, false);
		break;
	case 2:
		Board_LED_Set(LED1, false);
		Board_LED_Set(LED2, true);
		Board_LED_Set(LED3, false);
		break;
	case 3:
		Board_LED_Set(LED1, true);
		Board_LED_Set(LED2, true);
		Board_LED_Set(LED3, false);
		break;
	case 4:
		Board_LED_Set(LED1, false);
		Board_LED_Set(LED2, false);
		Board_LED_Set(LED3, true);
		break;
	case 5:
		Board_LED_Set(LED1, true);
		Board_LED_Set(LED2, false);
		Board_LED_Set(LED3, true);
		break;
	case 6:
		Board_LED_Set(LED1, false);
		Board_LED_Set(LED2, true);
		Board_LED_Set(LED3, true);
		break;
	case 7:
		Board_LED_Set(LED1, true);
		Board_LED_Set(LED2, true);
		Board_LED_Set(LED3, true);
		break;
	}

}
