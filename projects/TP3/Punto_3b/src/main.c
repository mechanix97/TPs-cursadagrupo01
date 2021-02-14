#include "main.h"
#include "sapi.h"


void processInput(char c){
	bool_t b;
	switch (c){
	case '1':
		b = gpioRead(LED1);
		gpioWrite(LED1, !b);
		break;
	case '2':
		b = gpioRead(LED2);
		gpioWrite(LED2, !b);
		break;
	case '3':
		b = gpioRead(LED3);
		gpioWrite(LED3, !b);
		break;
	case 'g':
		b = gpioRead(LEDG);
		gpioWrite(LEDG, !b);
		break;
	case 'r':
		b = gpioRead(LEDR);
		gpioWrite(LEDR, !b);
		break;
	case 'b':
		b = gpioRead(LEDB);
		gpioWrite(LEDB, !b);
		break;
	default:
		break;
	}
}



int main(void){

	boardConfig();
	uartConfig(UART_USB, 115200);
	tickConfig(50);




	uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
	uartInterrupt(UART_USB, true);


	while (1){

	}

	return 0;
}

void onRx(void* unused){
	char c = '0';
	uartReadByte(UART_USB, &c);
	processInput(c);
}
