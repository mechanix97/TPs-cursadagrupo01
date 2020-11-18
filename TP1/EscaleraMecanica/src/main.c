
#include "../inc/sc_types.h"
#include "../inc/main.h"
#include "../inc/TimerTicks.h"
#include "../gen/EscaleraMecanica.h"
#include "board.h"


#define TICKRATE_1MS		   (1000)				/* 1000 ticks per second */
#define TICKRATE_MS			(TICKRATE_1MS)	/* 1000 ticks per second */


volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static EscaleraMecanica statechart;

/*! This is a timed state machine that requires timer services */
//#define NOF_TIMERS (sizeof(EscaleraMecanicaTimeEvents)/sizeof(sc_boolean))

//TimerTicks ticks[NOF_TIMERS];


/*! \file This header defines prototypes for all functions that are required
 *  by the state machine implementation.
 *
 *  This is a state machine uses time events which require access to a timing
 *  service. Thus the function prototypes:
 *  - escaleraMecanica_setTimer and
 *  - escaleraMecanica_unsetTimer
 *  are defined.
 *
 *  This state machine makes use of operations declared in the state machines
 *  interface or internal scopes. Thus the function prototypes:
 *  - escaleraMecanicaIface_opLED
 *  are defined.
 *
 *  These functions will be called during a 'run to completion step' (runCycle)
 *  of the statechart.
 *  There are some constraints that have to be considered for the
 *  implementation of these functions:
 *  - never call the statechart API functions from within these functions.
 *  - make sure that the execution time is as short as possible.
 */

#define LED0_R    0
#define LED0_G    1
#define LED0_B    2
#define LED1      3
#define LED2      4
#define LED3      5


/** state machine user-defined external function (action)
 *
 * @param handle state machine instance
 * @param LEDNumber number of LED
 * @param onoff state machine operation parameter
 */
void escaleraMecanicaIface_opMotor( EscaleraMecanica* handle, sc_integer LEDNumber, sc_boolean State )
{
	Board_LED_Set(LEDNumber, State);
}


/*! * This is a timed state machine that requires timer services
 */

/*! This function has to set up timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be entered.
 *  \param evid An unique identifier of the event.
 *  \time_ms The time in milli seconds
 *  \periodic Indicates the the time event must be raised periodically until
 *   the timer is unset
 */
void escaleraMecanica_setTimer( EscaleraMecanica* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
{
	//SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be left.
 *  \param evid An unique identifier of the event.
 */
void escaleraMecanica_unsetTimer( EscaleraMecanica* handle, const sc_eventid evid )
{
	//UnsetTimerTick( ticks, NOF_TIMERS, evid );
}


/**
 * @brief	Hook on Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void){
	SysTick_Time_Flag = true;
}

/*! This function scan all EDU-CIAA-NXP buttons (TEC1, TEC2, TEC3 and TEC4),
 *  and return ID of pressed button (TEC1 or TEC2 or TEC3 or TEC4)
 *  or false if no button was pressed.
 */
uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;
	uint32_t idx;

	for (idx = 0; idx < 4; ++idx) {
		if (Board_TEC_GetStatus( idx ) == 0)
			ret |= 1 << idx;
	}
	return ret;
}


/**
 * @brief	main routine for statechart example: EDU-CIAA-NXP - EscaleraMecanica LED3
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t i;

	uint32_t BUTTON_Status;

	/* Generic Initialization */
	Board_Init();

	/* Init Ticks counter => TICKRATE_MS */
	SysTick_Config(SystemCoreClock / TICKRATE_MS);

	/* Init Timer Ticks */
	//InitTimerTicks( ticks, NOF_TIMERS );

	/* Statechart Initialization */
	escaleraMecanica_init( &statechart );
	escaleraMecanica_enter( &statechart );

	/* LED state is toggled in the main program */
	while (1) {
		/* The uC sleeps waiting for an interruption */
		__WFI();

		/* When a interrupt wakes to the uC, the main program validates it,
		 * checking the waited Flag */


			/* Then Get status of buttons */
			BUTTON_Status = Buttons_GetStatus_();

			/* Then if there are a pressed button */
			if (BUTTON_Status != 0){
				if(BUTTON_Status & 1){
					escaleraMecanicaIface_raise_evPresionS1(&statechart);
				} else if( BUTTON_Status & 2){
					escaleraMecanicaIface_raise_evPresionS2(&statechart);
				}else if( BUTTON_Status & 3){

				}else if( BUTTON_Status & 4){

				}else{

				}

			}
			else{

			}


			/* Then Run an Cycle of Statechart */
			escaleraMecanica_runCycle(&statechart);		// Run Cycle of Statechart

	}
}


/** @} doxygen end group definition */

/*==================[end of file]============================================*/
