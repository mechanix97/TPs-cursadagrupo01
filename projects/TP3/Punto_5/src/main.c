#include "sapi.h"
#include <string.h>

//Funciones
void itoa(int m, char s[]);


int main(void){

  uint16_t muestra = 0;
  static char buffer[10];
  delay_t delay;
  
  boardConfig();                                 
  uartConfig( UART_USB, 115200 );               
  adcConfig( ADC_ENABLE );                      
  delayConfig( delay, 500 );

   while(1) {


      if ( delayRead( &delay ) ){

        muestra = adcRead( CH1 );
        uartWriteString( UART_USB, "Valor ADC CH1: " );
        itoa(muestra, buffer);


        uartWriteString( UART_USB, buffer );
        uartWriteString( UART_USB, "\r\n" );
      }

   }

   return 0 ;
}



void itoa(int m, char s[]){

 }