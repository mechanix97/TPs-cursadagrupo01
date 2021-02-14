#include "main.h"

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

static myButton_t button1;
static myButton_t button2;
static myButton_t button3;
static myButton_t button4;


void buttonFalled(myButton_t* b){
	/*uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->name );
	uartWriteString( UART_USB, "\r\n" );*/

	switch(b->button){
		case TEC1:
			gpioWrite(LEDG,HIGH);
			break;
		case TEC2:
			gpioWrite(LED1,HIGH);
			break;
		case TEC3:
			gpioWrite(LED2,HIGH);
			break;
		case TEC4:
			gpioWrite(LED3,HIGH);
			break;
	}
}

void  buttonRaised(myButton_t* b){
	/*uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->name );
	uartWriteString( UART_USB, "\r\n" );*/

	switch(b->button){
		case TEC1:
			gpioWrite(LEDG,LOW);
			break;
		case TEC2:
			gpioWrite(LED1,LOW);
			break;
		case TEC3:
			gpioWrite(LED2,LOW);
			break;
		case TEC4:
			gpioWrite(LED3,LOW);
			break;
		}
}

void InitButton(myButton_t* b, gpioMap_t button_number,  char* name){
	b->button_state = BUTTON_STATE_OFF;
	b->button = button_number;
	b->name = name;
}


void buttonUpdate(myButton_t* b){
	switch(b->button_state){
		case BUTTON_STATE_OFF:
			if(gpioRead(b->button) == LOW)
				b->button_state = BUTTON_RISING;
			break;

		case BUTTON_STATE_ON:
			if(gpioRead(b->button) == HIGH)
				b->button_state = BUTTON_FALLING;
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

int main(void){

	boardConfig();
	uartConfig(UART_USB, 115200);
	uartConfig(UART_232, 115200);
	tickConfig(50);

	uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
	uartInterrupt(UART_USB, true);

	uartCallbackSet(UART_232, UART_RECEIVE, onRx232, NULL);
	uartInterrupt(UART_232, true);

	InitButton(&button1, TEC1, "Boton 1");
	InitButton(&button2, TEC2, "Boton 2");
	InitButton(&button3, TEC3, "Boton 3");
	InitButton(&button4, TEC4, "Boton 4");

	while (1){
		buttonUpdate(&button1);
		buttonUpdate(&button2);
		buttonUpdate(&button3);
		buttonUpdate(&button4);
	}

	return 0;
}

void onRx(void* unused){
	char c = '0';
	uartReadByte( UART_USB , &c);
	uartWriteByte( UART_232 , c);
	processInput(c);
}

void onRx232 (void* unused){
	char c = '0';
	uartReadByte( UART_232 , &c);
	uartWriteByte( UART_USB , c);
	processInput(c);
}

