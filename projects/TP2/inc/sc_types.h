
#ifndef SC_TYPES_H_
#define SC_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif 

#include <stdint.h>
#include <stdbool.h>

#define sc_string		char*
 
typedef bool			sc_boolean;
typedef int_fast16_t	sc_short;
typedef uint_fast16_t	sc_ushort;
typedef int32_t			sc_integer;
typedef uint32_t		sc_uinteger;

typedef double			sc_real;

typedef void*			sc_eventid;

typedef intptr_t		sc_intptr_t;

#ifdef __cplusplus
}
#endif

#ifndef sc_null
	#ifdef __cplusplus
		#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)
	  		#define sc_null nullptr
		#else
			#define sc_null 0
		#endif
	#else
		#define sc_null ((void *)0)
	#endif
#endif

#define bool_true true
#define bool_false false

#endif /* SC_TYPES_H_ */
