#ifndef __O_TYPEDEF_H__
#define __O_TYPEDEF_H__

//#include <limits.h>

typedef enum {
    O_False_e = 0,
    O_True_e = 1,
}O_bool_e;



typedef signed char             int8_t;
typedef unsigned char           uint8_t;

typedef signed short            int16_t;
typedef unsigned short          uint16_t;

typedef signed int              int32_t;
typedef unsigned int            uint32_t;

typedef signed long long        int64_t;
typedef unsigned long long      uint64_t;

#define O_STATUS    int32_t
#define O_FAIL      (-1)
#define O_OK        0

#endif
