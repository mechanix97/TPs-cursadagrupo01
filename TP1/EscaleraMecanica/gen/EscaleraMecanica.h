/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef ESCALERAMECANICA_H_
#define ESCALERAMECANICA_H_

#include "sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'EscaleraMecanica'.
*/

/*! Define number of states in the state enum */

#define ESCALERAMECANICA_STATE_COUNT 12

/*! Define dimension of the state configuration vector for orthogonal states. */
#define ESCALERAMECANICA_MAX_ORTHOGONAL_STATES 4

/*! Define maximum number of time events that can be active at once */
#define ESCALERAMECANICA_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_ESCALERAMECANICA_TECX_DEBOUNCE 0
#define SCVI_ESCALERAMECANICA_TECX_NO_OPRIMIDO 0
#define SCVI_ESCALERAMECANICA_TECX_OPRIMIDO 0
#define SCVI_ESCALERAMECANICA_TECX_VALIDACION 0
#define SCVI_ESCALERAMECANICA_COPY_1_MAIN_REGION_ESPERA 1
#define SCVI_ESCALERAMECANICA_MAIN_REGION_STOP 2
#define SCVI_ESCALERAMECANICA_MAIN_REGION_SUBIR 2
#define SCVI_ESCALERAMECANICA_MAIN_REGION_BAJAR 2
#define SCVI_ESCALERAMECANICA_MAIN_REGION_FINALIZ__BAJADA 2
#define SCVI_ESCALERAMECANICA_MAIN_REGION_FINALIZ__SUBIDA 2
#define SCVI_ESCALERAMECANICA_LUZ_ROJA___FRENADO 3
#define SCVI_ESCALERAMECANICA_LUZ_VERDE___FUNCIONANDO 3

/*! Enumeration of all states */ 
typedef enum
{
	EscaleraMecanica_last_state,
	EscaleraMecanica_TECX_DEBOUNCE,
	EscaleraMecanica_TECX_NO_OPRIMIDO,
	EscaleraMecanica_TECX_OPRIMIDO,
	EscaleraMecanica_TECX_VALIDACION,
	EscaleraMecanica_Copy_1_main_region_ESPERA,
	EscaleraMecanica_main_region_STOP,
	EscaleraMecanica_main_region_SUBIR,
	EscaleraMecanica_main_region_BAJAR,
	EscaleraMecanica_main_region_FINALIZ__BAJADA,
	EscaleraMecanica_main_region_FINALIZ__SUBIDA,
	EscaleraMecanica_Luz_ROJA___FRENADO,
	EscaleraMecanica_Luz_VERDE___FUNCIONANDO
} EscaleraMecanicaStates;

/*! Type definition of the data structure for the EscaleraMecanicaIface interface scope. */
typedef struct
{
	sc_boolean evPresionS1_raised;
	sc_boolean evPresionS2_raised;
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_integer personas;
} EscaleraMecanicaIface;


/* Declaration of constants for scope EscaleraMecanicaIface. */
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_ON;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_OFF;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_ONOFF;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_TOGGLE;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LEDR;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LEDG;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LEDB;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LED1;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LED2;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_LED3;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_LED_ON;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_LED_OFF;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_TEC1;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_TEC2;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_TEC3;
extern const sc_integer ESCALERAMECANICA_ESCALERAMECANICAIFACE_TEC4;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_SUBIR;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_BAJAR;
extern const sc_boolean ESCALERAMECANICA_ESCALERAMECANICAIFACE_STOP;


/*! Type definition of the data structure for the EscaleraMecanicaInternal interface scope. */
typedef struct
{
	sc_boolean siRojo_raised;
	sc_boolean siVerde_raised;
	sc_boolean siTECXOK_raised;
	sc_integer viTecla;
} EscaleraMecanicaInternal;



/*! Type definition of the data structure for the EscaleraMecanicaTimeEvents interface scope. */
typedef struct
{
	sc_boolean escaleraMecanica_TECX_DEBOUNCE_tev0_raised;
} EscaleraMecanicaTimeEvents;




/*! 
 * Type definition of the data structure for the EscaleraMecanica state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	EscaleraMecanicaStates stateConfVector[ESCALERAMECANICA_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	EscaleraMecanicaIface iface;
	EscaleraMecanicaInternal internal;
	EscaleraMecanicaTimeEvents timeEvents;
} EscaleraMecanica;



/*! Initializes the EscaleraMecanica state machine data structures. Must be called before first usage.*/
extern void escaleraMecanica_init(EscaleraMecanica* handle);

/*! Activates the state machine */
extern void escaleraMecanica_enter(EscaleraMecanica* handle);

/*! Deactivates the state machine */
extern void escaleraMecanica_exit(EscaleraMecanica* handle);

/*! Performs a 'run to completion' step. */
extern void escaleraMecanica_runCycle(EscaleraMecanica* handle);

/*! Raises a time event. */
extern void escaleraMecanica_raiseTimeEvent(EscaleraMecanica* handle, sc_eventid evid);

/*! Raises the in event 'evPresionS1' that is defined in the default interface scope. */ 
extern void escaleraMecanicaIface_raise_evPresionS1(EscaleraMecanica* handle);

/*! Raises the in event 'evPresionS2' that is defined in the default interface scope. */ 
extern void escaleraMecanicaIface_raise_evPresionS2(EscaleraMecanica* handle);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void escaleraMecanicaIface_raise_evTECXNoOprimido(EscaleraMecanica* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void escaleraMecanicaIface_raise_evTECXOprimido(EscaleraMecanica* handle, sc_integer value);

/*! Gets the value of the variable 'ON' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_oN(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'OFF' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_oFF(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'ONoFF' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_oNoFF(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'TOGGLE' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_tOGGLE(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lEDR(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lEDG(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lEDB(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lED1(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lED2(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_lED3(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_lED_ON(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_lED_OFF(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_tEC1(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_tEC2(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_tEC3(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_tEC4(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'SUBIR' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_sUBIR(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'BAJAR' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_bAJAR(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'STOP' that is defined in the default interface scope. */ 
extern sc_boolean escaleraMecanicaIface_get_sTOP(const EscaleraMecanica* handle);
/*! Gets the value of the variable 'personas' that is defined in the default interface scope. */ 
extern sc_integer escaleraMecanicaIface_get_personas(const EscaleraMecanica* handle);
/*! Sets the value of the variable 'personas' that is defined in the default interface scope. */ 
extern void escaleraMecanicaIface_set_personas(EscaleraMecanica* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean escaleraMecanica_isActive(const EscaleraMecanica* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean escaleraMecanica_isFinal(const EscaleraMecanica* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean escaleraMecanica_isStateActive(const EscaleraMecanica* handle, EscaleraMecanicaStates state);


#ifdef __cplusplus
}
#endif 

#endif /* ESCALERAMECANICA_H_ */
