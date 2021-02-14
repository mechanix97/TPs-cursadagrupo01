/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef ORDENADORMOTO_H_
#define ORDENADORMOTO_H_

#include "../inc/sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'OrdenadorMoto'.
*/

/*! Define number of states in the state enum */

#define ORDENADORMOTO_STATE_COUNT 12

/*! Define dimension of the state configuration vector for orthogonal states. */
#define ORDENADORMOTO_MAX_ORTHOGONAL_STATES 2

/*! Define maximum number of time events that can be active at once */
#define ORDENADORMOTO_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA0 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA1 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA2 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA3 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA4 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA5 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA6 0
#define SCVI_ORDENADORMOTO_MAIN_REGION_PANTALLA7 0
#define SCVI_ORDENADORMOTO_DEBOUNCER_DEBOUNCE 1
#define SCVI_ORDENADORMOTO_DEBOUNCER_NO_OPRIMIDO 1
#define SCVI_ORDENADORMOTO_DEBOUNCER_OPRIMIDO 1
#define SCVI_ORDENADORMOTO_DEBOUNCER_VALIDACION 1

/*! Enumeration of all states */ 
typedef enum
{
	OrdenadorMoto_last_state,
	OrdenadorMoto_main_region_Pantalla0,
	OrdenadorMoto_main_region_Pantalla1,
	OrdenadorMoto_main_region_Pantalla2,
	OrdenadorMoto_main_region_Pantalla3,
	OrdenadorMoto_main_region_Pantalla4,
	OrdenadorMoto_main_region_Pantalla5,
	OrdenadorMoto_main_region_Pantalla6,
	OrdenadorMoto_main_region_Pantalla7,
	OrdenadorMoto_Debouncer_DEBOUNCE,
	OrdenadorMoto_Debouncer_NO_OPRIMIDO,
	OrdenadorMoto_Debouncer_OPRIMIDO,
	OrdenadorMoto_Debouncer_VALIDACION
} OrdenadorMotoStates;

/*! Type definition of the data structure for the OrdenadorMotoIface interface scope. */
typedef struct
{
	sc_boolean evBoton_raised;
	sc_boolean evNoBoton_raised;
	sc_boolean evCambiarPantalla_raised;
	sc_integer pantalla;
} OrdenadorMotoIface;


/* Declaration of constants for scope OrdenadorMotoIface. */
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA0;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA1;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA2;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA3;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA4;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA5;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA6;
extern const sc_integer ORDENADORMOTO_ORDENADORMOTOIFACE_PANTALLA7;




/*! Type definition of the data structure for the OrdenadorMotoTimeEvents interface scope. */
typedef struct
{
	sc_boolean ordenadorMoto_Debouncer_DEBOUNCE_tev0_raised;
} OrdenadorMotoTimeEvents;




/*! 
 * Type definition of the data structure for the OrdenadorMoto state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	OrdenadorMotoStates stateConfVector[ORDENADORMOTO_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	OrdenadorMotoIface iface;
	OrdenadorMotoTimeEvents timeEvents;
} OrdenadorMoto;



/*! Initializes the OrdenadorMoto state machine data structures. Must be called before first usage.*/
extern void ordenadorMoto_init(OrdenadorMoto* handle);

/*! Activates the state machine */
extern void ordenadorMoto_enter(OrdenadorMoto* handle);

/*! Deactivates the state machine */
extern void ordenadorMoto_exit(OrdenadorMoto* handle);

/*! Performs a 'run to completion' step. */
extern void ordenadorMoto_runCycle(OrdenadorMoto* handle);

/*! Raises a time event. */
extern void ordenadorMoto_raiseTimeEvent(OrdenadorMoto* handle, sc_eventid evid);

/*! Raises the in event 'evBoton' that is defined in the default interface scope. */ 
extern void ordenadorMotoIface_raise_evBoton(OrdenadorMoto* handle);

/*! Raises the in event 'evNoBoton' that is defined in the default interface scope. */ 
extern void ordenadorMotoIface_raise_evNoBoton(OrdenadorMoto* handle);

/*! Raises the in event 'evCambiarPantalla' that is defined in the default interface scope. */ 
extern void ordenadorMotoIface_raise_evCambiarPantalla(OrdenadorMoto* handle);

/*! Gets the value of the variable 'pantalla0' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla0(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla1' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla1(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla2' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla2(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla3' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla3(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla4' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla4(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla5' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla5(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla6' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla6(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla7' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla7(const OrdenadorMoto* handle);
/*! Gets the value of the variable 'pantalla' that is defined in the default interface scope. */ 
extern sc_integer ordenadorMotoIface_get_pantalla(const OrdenadorMoto* handle);
/*! Sets the value of the variable 'pantalla' that is defined in the default interface scope. */ 
extern void ordenadorMotoIface_set_pantalla(OrdenadorMoto* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean ordenadorMoto_isActive(const OrdenadorMoto* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean ordenadorMoto_isFinal(const OrdenadorMoto* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean ordenadorMoto_isStateActive(const OrdenadorMoto* handle, OrdenadorMotoStates state);


#ifdef __cplusplus
}
#endif 

#endif /* ORDENADORMOTO_H_ */