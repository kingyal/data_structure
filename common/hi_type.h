#ifndef __HI_TYPE_H__
#define __HI_TYPE_H__

#define HI_NULL 0L
typedef void    hi_void;
typedef char    hi_s8;
typedef unsigned char   hi_u8;
typedef short   hi_s16;
typedef unsigned short  hi_u16;
typedef int hi_s32;
typedef unsigned int    hi_u32;

typedef long long int   hi_s64;
typedef unsigned long long int  hi_u64;

#if __WORDSIZE == 64
typedef long int    intptr_t;
typedef unsigned long int   uintptr_t;
#else
typedef int     intptr_t;
typedef unsigned int    uintptr_t;
#endif

#define HI_SUCCESS  0
#define HI_FAILURE   -1
#endif