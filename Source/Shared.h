#ifndef NEPHQ2_SHARED_H
#define NEPHQ2_SHARED_H 1

//
// Standard Types
//

#ifdef __cplusplus
	#include <cstdint>
	#include <string>
	#include <map>
#else
	#include <stdint.h>
	#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (defined(_MSC_VER) && (_MSC_VER >= 1800))
		#include <stdbool.h>
	#endif
#endif

#if defined(__cplusplus) || defined(__bool_true_false_are_defined)
typedef bool bool_t;
#else
typedef enum { false, true } bool_t;
#endif

#endif
