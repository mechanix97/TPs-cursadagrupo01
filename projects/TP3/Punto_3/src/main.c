#include "main.h"

static myButton_t button1;
static myButton_t button2;
static myButton_t button3;
static myButton_t button4;
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



void InitButton(myButton_t* b, gpioMap_t button_number, char* name){
	b->button_state = BUTTON_STATE_OFF;
	b->button = button_number;
	b->name = name;
}

void buttonFalled(myButton_t* b){
	uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->name );
	uartWriteString( UART_USB, "\r\n" );
}

void  buttonRaised(myButton_t* b){
	uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->name );
	uartWriteString( UART_USB, "\r\n" );
}


void buttonUpdate(myButton_t* b){
	switch(b->button_state){
		case BUTTON_STATE_OFF:
			if(gpioRead(b->button) == LOW)
				b->button_state = BUTTON_STATE_RISING;
			break;
			
		case BUTTON_STATE_ON:
			if(gpioRead(b->button) == HIGH)
				b->button_state = BUTTON_STATE_FALLING;
			break;
			
		case BUTTON_STATE_RISING:
			if(gpioRead(b->button) == LOW){
				b->button_state = BUTTON_STATE_ON;
				buttonRaised(b);
			} else
				b->button_state = BUTTON_STATE_OFF;
			break;
			
		case BUTTON_STATE_FALLING:
			if(gpioRead(b->button) == HIGH){
				b->button_state = BUTTON_STATE_OFF;
				buttonFalled(b);
			} else
				b->button_state = BUTTON_STATE_ON;
			break;
	}
}



