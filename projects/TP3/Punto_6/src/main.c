#include "sapi.h"        

char* itoa(int value, char* result, int base) {
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}


void setDacValue( uint8_t data){


	switch (data){

		case '0':
			dacWrite( DAC, 0);
			break;
		case '1':
			dacWrite( DAC, 114);
			break;
		case '2':
			dacWrite( DAC, 228);
			break;
		case '3':
			dacWrite( DAC, 342);
			break;
		case '4':
			dacWrite( DAC, 456);
			break;
		case '5':
			dacWrite( DAC, 570);
			break;
		case '6':
			dacWrite( DAC, 684);
			break;
		case '7':
			dacWrite( DAC, 798);
			break;
		case '8':
			dacWrite( DAC, 912);
			break;
		case '9':
			dacWrite( DAC, 1023);
			break;
		default:
			break;

	}

}

int main(void){


   boardConfig();

   uartConfig( UART_USB, 115200 );

   adcConfig( ADC_ENABLE ); 
   dacConfig( DAC_ENABLE ); 


   uint8_t data  = 0;

   static char uartBuff[10];

   uint16_t muestra = 0;

   delay_t delay1;

   delayConfig( &delay1, 500 );

   while(1) {

	  if(  uartReadByte( UART_USB, &data ) ){
		  setDacValue(data);

   	  }

	  if ( delayRead( &delay1 ) ){

	           muestra = adcRead( CH1 );

				uartWriteString( UART_USB, "ADC CH1 value: " );

				itoa( muestra, uartBuff, 10 ); 
				uartWriteString( UART_USB, uartBuff );
				uartWriteString( UART_USB, ";\r\n" );
	  }

   }


   return 0 ;
}

