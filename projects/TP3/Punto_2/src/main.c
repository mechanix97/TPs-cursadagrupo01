#include "main.h"
#include "sapi.h"


static button_t button1;
static button_t button2;
static button_t button3;
static button_t button4;


int main(void)
{
	boardConfig();
	uartConfig(UART_USB, 115200);
	tickConfig(50);
	

	InitButton(&button1, BUTTON1);
	InitButton(&button2, BUTTON2);
	InitButton(&button3, BUTTON3);
	InitButton(&button4, BUTTON4);


   delay(500);

   while(1) {
   		buttonUpdate(&button1);
		buttonUpdate(&button2);
		buttonUpdate(&button3);
		buttonUpdate(&button4);
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

	switch(b->button){
		case BUTTON1:
			gpioWrite(LEDG,HIGH);
			break;
		case BUTTON2:
			gpioWrite(LED1,HIGH);
			break;
		case BUTTON3:
			gpioWrite(LED2,HIGH);
			break;
		case BUTTON4:
			gpioWrite(LED3,HIGH);
			break;
	}
}

void  buttonRaised(button_t* b){
	uartWriteString( UART_USB, "Boton  " );
	uartWriteString( UART_USB, b->button );
	uartWriteString( UART_USB, "\r\n" );

	switch(b->button){
		case BUTTON1:
			gpioWrite(LEDG,LOW);
			break;
		case BUTTON2:
			gpioWrite(LED1,LOW);
			break;
		case BUTTON3:
			gpioWrite(LED2,LOW);
			break;
		case BUTTON4:
			gpioWrite(LED3,LOW);
			break;
		}
}