/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef HORNOMICROONDAS_H_
#define HORNOMICROONDAS_H_

#include "../inc/sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'HornoMicroondas'.
*/

/*! Define number of states in the state enum */

#define HORNOMICROONDAS_STATE_COUNT 5

/*! Define dimension of the state configuration vector for orthogonal states. */
#define HORNOMICROONDAS_MAX_ORTHOGONAL_STATES 2

/*! Define maximum number of time events that can be active at once */
#define HORNOMICROONDAS_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_HORNOMICROONDAS_MODO_MODO_0 0
#define SCVI_HORNOMICROONDAS_MODO_MODO_1 0
#define SCVI_HORNOMICROONDAS_MODO_MODO_2 0
#define SCVI_HORNOMICROONDAS_COCCION_STAND_BY 1
#define SCVI_HORNOMICROONDAS_COCCION_COCINANDO 1

/*! Enumeration of all states */ 
typedef enum
{
	HornoMicroondas_last_state,
	HornoMicroondas_Modo_Modo_0,
	HornoMicroondas_Modo_Modo_1,
	HornoMicroondas_Modo_Modo_2,
	HornoMicroondas_Coccion_Stand_By,
	HornoMicroondas_Coccion_Cocinando
} HornoMicroondasStates;

/*! Type definition of the data structure for the HornoMicroondasIface interface scope. */
typedef struct
{
	sc_boolean evModo_raised;
	sc_boolean evIniciar_raised;
	sc_boolean evParar_raised;
	sc_boolean evPuertaAbierta_raised;
} HornoMicroondasIface;


/* Declaration of constants for scope HornoMicroondasIface. */
extern const sc_integer HORNOMICROONDAS_HORNOMICROONDASIFACE_MODO0;
extern const sc_integer HORNOMICROONDAS_HORNOMICROONDASIFACE_MODO1;
extern const sc_integer HORNOMICROONDAS_HORNOMICROONDASIFACE_MODO2;
extern const sc_integer HORNOMICROONDAS_HORNOMICROONDASIFACE_MODO;




/*! Type definition of the data structure for the HornoMicroondasTimeEvents interface scope. */
typedef struct
{
	sc_boolean hornoMicroondas_Coccion_Cocinando_tev0_raised;
} HornoMicroondasTimeEvents;




/*! 
 * Type definition of the data structure for the HornoMicroondas state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	HornoMicroondasStates stateConfVector[HORNOMICROONDAS_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	HornoMicroondasIface iface;
	HornoMicroondasTimeEvents timeEvents;
} HornoMicroondas;



/*! Initializes the HornoMicroondas state machine data structures. Must be called before first usage.*/
extern void hornoMicroondas_init(HornoMicroondas* handle);

/*! Activates the state machine */
extern void hornoMicroondas_enter(HornoMicroondas* handle);

/*! Deactivates the state machine */
extern void hornoMicroondas_exit(HornoMicroondas* handle);

/*! Performs a 'run to completion' step. */
extern void hornoMicroondas_runCycle(HornoMicroondas* handle);

/*! Raises a time event. */
extern void hornoMicroondas_raiseTimeEvent(HornoMicroondas* handle, sc_eventid evid);

/*! Raises the in event 'evModo' that is defined in the default interface scope. */ 
extern void hornoMicroondasIface_raise_evModo(HornoMicroondas* handle);

/*! Raises the in event 'evIniciar' that is defined in the default interface scope. */ 
extern void hornoMicroondasIface_raise_evIniciar(HornoMicroondas* handle);

/*! Raises the in event 'evParar' that is defined in the default interface scope. */ 
extern void hornoMicroondasIface_raise_evParar(HornoMicroondas* handle);

/*! Raises the in event 'evPuertaAbierta' that is defined in the default interface scope. */ 
extern void hornoMicroondasIface_raise_evPuertaAbierta(HornoMicroondas* handle);

/*! Gets the value of the variable 'MODO0' that is defined in the default interface scope. */ 
extern sc_integer hornoMicroondasIface_get_mODO0(const HornoMicroondas* handle);
/*! Gets the value of the variable 'MODO1' that is defined in the default interface scope. */ 
extern sc_integer hornoMicroondasIface_get_mODO1(const HornoMicroondas* handle);
/*! Gets the value of the variable 'MODO2' that is defined in the default interface scope. */ 
extern sc_integer hornoMicroondasIface_get_mODO2(const HornoMicroondas* handle);
/*! Gets the value of the variable 'MODO' that is defined in the default interface scope. */ 
extern sc_integer hornoMicroondasIface_get_mODO(const HornoMicroondas* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean hornoMicroondas_isActive(const HornoMicroondas* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean hornoMicroondas_isFinal(const HornoMicroondas* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean hornoMicroondas_isStateActive(const HornoMicroondas* handle, HornoMicroondasStates state);


#ifdef __cplusplus
}
#endif 

#endif /* HORNOMICROONDAS_H_ */