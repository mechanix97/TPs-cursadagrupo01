#include "main.h"

static button_t button1;
static button_t button2;
static button_t button3;
static button_t button4;
static char led_char;

void onTickUpdate(){
	buttonUpdate(&button1);
	buttonUpdate(&button2);
	buttonUpdate(&button3);
	buttonUpdate(&button4);
}

void printReference() {
	printf("Encender Led R: Presione A \n");
	printf("Encender Led 1: Presione B \n");
	printf("Encender Led 2: Presione C \n");
	printf("Encender Led 3: Presione D \n");
	printf("Apagar Led R: Presione W \n");
	printf("Apagar Led 1: Presione X \n");
	printf("Apagar Led 2: Presione Y \n");
	printf("Apagar Led 3: Presione Z \n");
}

void uartRead(void* unused){
	led_char = uartRxRead(UART_USB);
	printf("Se ingreso: %c", led_char);
	switch(led_char){
		case 'A':
			gpioWrite(LEDR, 1);
			break;
		case 'B':
			gpioWrite(LED1, 1);
			break;
		case 'C':
			gpioWrite(LED2, 1);
			break;
		case 'D':
			gpioWrite(LED3, 1);
			break;			
		case 'W':
			gpioWrite(LEDR, 0);
			break;
		case 'X':
			gpioWrite(LED1, 0);
			break;
		case 'Y':
			gpioWrite(LED2, 0);
			break;
		case 'Z':
			gpioWrite(LED3, 0);
			break;			
	}
}

int main(void)
{
	boardConfig();
	uartConfig(UART_USB, 115200);
	tickConfig(50);

	InitButton(&button1, BUTTON1);
	InitButton(&button2, BUTTON2);
	InitButton(&button3, BUTTON3);
	InitButton(&button4, BUTTON4);

   	tickCallbackSet( onTickUpdate, NULL );

	uartCallbackSet(UART_USB, UART_RECEIVE, uartRead, NULL);
	uartInterrupt(UART_USB, true);

   	printReference();
	
	delay(500);

   while(1) {
   }

   return 0 ;
}



void InitButton(button_t* b, gpioMap_t button_number){
	b->button_state = BUTTON_OFF;
	b->button = button_number;
}


void buttonUpdate(button_t* b){
	switch(b->button_state){
		case BUTTON_OFF:
			if(gpioRead(b->button) == LOW)
				b->button_state = BUTTON_RISING;
			break;
			
		case BUTTON_ON:
			if(gpioRead(b->button) == HIGH)
				b->button_state = BUTTON_FALLING;
			break;
			
		case BUTTON_RISING:
			if(gpioRead(b->button) == LOW){
				b->button_state = BUTTON_ON;
				ButtonRaised(b);
			} else
				b->button_state = BUTTON_OFF;
			break;
			
		case BUTTON_FALLING:
			if(gpioRead(b->button) == HIGH){
				b->button_state = BUTTON_OFF;
				ButtonFalled(b);
			} else
				b->button_state = BUTTON_ON;
			break;
	}
}



void buttonFalled(button_t* b){
	uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->button );
	uartWriteString( UART_USB, "\r\n" );
}

void  buttonRaised(button_t* b){
	uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->button );
	uartWriteString( UART_USB, "\r\n" );
}