#ifndef _INCLUDED_PREDEFINED
#define _INCLUDED_PREDEFINED

#include <stdint.h>

typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef int8_t byte;

#if __WORDSIZE == 32
typedef int32_t word;
#elif __WORDSIZE == 64
typedef int64_t word;
#endif

typedef _Bool boolean;
#define false   (!!0)
#define true    (!false)
#define FALSE   false
#define TRUE    true

typedef float float32;
typedef double float64;

#define null    ((void *) 0)

#define NUL     ('\0')

#define public
#define internal

#endif // _INCLUDED_PREDEFINED
