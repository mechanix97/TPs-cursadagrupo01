#include "sapi.h"

static char led_char;


void printReference() {
	printf("+ brillo Led1: A\r\n");
	printf("+ brillo Led2: B\r\n");
	printf("+ brillo Led3: C\r\n");
	printf("- brillo Led1: X\r\n");
	printf("- brillo Led2: Y\r\n");
	printf("- brillo Led3: Z\r\n");
}

void uartRead(void* unused){
	led_char = uartRxRead(UART_USB);
	printf("Se ingreso: %c", led_char);
	switch(led_char){
		case 'A':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1) +1, rgbReadDutyGreen(RGB_1), rgbReadDutyBlue(RGB_1));
			break;
		case 'X':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1) -1, rgbReadDutyGreen(RGB_1), rgbReadDutyBlue(RGB_1));
			break;
		case 'B':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1), rgbReadDutyGreen(RGB_1) + 1, rgbReadDutyBlue(RGB_1));
			break;
		case 'Y':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1), rgbReadDutyGreen(RGB_1)-1, rgbReadDutyBlue(RGB_1));
			break;
		case 'C':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1), rgbReadDutyGreen(RGB_1), rgbReadDutyBlue(RGB_1)+1);
			break;
		case 'Z':
			rgbWriteRaw(RGB_1, rgbReadDutyRed(RGB_1), rgbReadDutyGreen(RGB_1), rgbReadDutyBlue(RGB_1)-1);
			break;
	}
}


int main(void)
{

	boardConfig();
	uartConfig(UART_USB, 115200);
	tickConfig(50);

	rgbConfig (RGB_1, LEDR, LEDG, LEDB);

	uartCallbackSet(UART_USB, UART_RECEIVE, uartRead, NULL);
	
	uartInterrupt(UART_USB, true);

	printReference();

	delay(500);

   while(1) {
   }

   return 0 ;
}


