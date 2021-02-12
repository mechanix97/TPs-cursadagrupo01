<h1> Documentación de funciones </h1>

<h2> uartConfig( UART_USB, 115200 ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe por parametros la configuración inicial para inicializar la UART de un puerto serie </li>
  <li> En este caso inicializará UART_USB con un baud rate de 115200 </li>
  <li> Algunas de las funciones utilizadas son : Chip_UART_Init, Chip_UART_SetBaud, Chip_UART_SetupFIFOS, Chip_UART_ReadByte, Chip_UART_TXEnable , Chip_SCU_PinMux </li>
</ul>

<h2> adcConfig( ADC_ENABLE ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_adc.c </li>
  <li> Recibe por parametros los datos para realizar la configuración del ADC </li>
  <li> En este caso estamos habilitando el ADC (ADC_ENABLE) </li>
  <li> Algunas de las funciones utilizadas son : Chip_ADC_Init, Chip_ADC_SetBurstCmd, Chip_ADC_SetSampleRate, Chip_ADC_EnableChannel, Chip_ADC_Int_SetChannelCmd, Chip_ADC_DeInit
 </li>
</ul>

<h2> dacConfig( DAC_ENABLE  ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_adc.c </li>
  <li> Recibe por parametros los datos para realizar la configuración del DAC </li>
  <li> En este caso estamos habilitando el DAC (ADC_ENABLE) </li>
  <li> Algunas de las funciones utilizadas son : Chip_Clock_EnableOpts, Chip_DAC_SetBias, Chip_DAC_ConfigDAConverterControl, Chip_DAC_UpdateValue, Chip_DAC_DeInit
 </li>
</ul>


<h2> delayConfig( &delay, 500 ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_delay.c </li>
  <li> Recibe por parametros los datos para la configuración de un delay </li>
  <li> En este caso estamos recibiendo un puntero y el tiempo que va a durar el delay</li>
 </li>
</ul>

<h2> muestra = adcRead( CH1 ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_delay.c </li>
  <li> Recibe por parametro el valor de un canal del cual se va a leer. Se guarda el valor leido en muestra</li>
  <li> En este caso estamos diciendo que lea del canal 1</li>
  <li> Algunas de las funciones utilizadas son : Chip_ADC_EnableChannel, Chip_ADC_SetStartMode, Chip_ADC_ReadStatus, Chip_ADC_ReadValue, Chip_ADC_EnableChannel
 </li>
</ul>

<h2> uartReadByte( UART_USB, &dato ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe por parametro un byte del RX del UART y un puntero al dato</li>
  <li> En este caso lee del UART_USB y guarda el valor en la variable pasada por puntero (dato)</li>
  <li> Algunas de las funciones utilizadas son :uartRxReady, uartRxRead
 </li>
</ul>

<h2> uartWriteByte( UART_USB, dato ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe por parametro un byte del TX del UART y un byte como dato</li>
  <li> En este caso escribe el valor pasado como segundo argumento (dato) en el TX de UART_USB</li>
  <li> Algunas de las funciones utilizadas son :uartTxReady, uartTxWrite
 </li>
</ul>

<h2> uartWriteString( UART_USB, "ADC CH1 value: " ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe la UART y una cadena de caracteres</li>
  <li> En este caso manda la cadena de caracteres pasada como segundo argumento por la UART_USB</li>
  <li> Algunas de las funciones utilizadas son :uartWriteByte
 </li>
</ul>

<h2> dacWrite( DAC, muestra ) </h2>
<ul>
  <li> Se encuentra dentro de sapi_dac.c </li>
  <li> Recibe la DAC y un valor para escribir sobre esta</li>
  <li> En este caso se escribe el valor contenido en la variable muestra en el DAC. El valor muestra es analogico entre 0 y 1023 </li>
  <li> Algunas de las funciones utilizadas son :Chip_DAC_UpdateValue
 </li>
</ul>

<h2> uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe la UART, el evento para activar la interrupcion y la funcion a ejecutarse cuando ocurra la interrupcion </li>
  <li> En este caso estamos seteando un Callback a una interrupcion de la UART_USB, le estamos diciendo que es una interrupcion por recepcion y le estamos diciendo que funcion debe ejecutar cuando esto ocurra </li>
  <li> Algunas de las funciones utilizadas son :Chip_UART_IntEnable
 </li>
</ul>

<h2> uartInterrupt(UART_USB, true) </h2>
<ul>
  <li> Se encuentra dentro de sapi_uart.c </li>
  <li> Recibe la UART y un booleano. En funcion del segundo parametro (true o false) se habilita (o se deshabilita) las interrupciones en el UART </li>
  <li> En este caso estamos diciendo que las interrupciones en la UART_USB estan habilitadas</li>
  <li> Algunas de las funciones utilizadas son :NVIC_SetPriority, NVIC_EnableIRQ, NVIC_DisableIRQ
 </li>
</ul>
