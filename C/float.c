#include <stdio.h>

typedef unsigned int    UINT32;
typedef unsigned char    U8;
typedef unsigned int    uint32_t;
typedef unsigned char    uint8_t;

void DisplayFloatNum(UINT32 value,UINT32 dotLen,UINT32 decimalBit,UINT32 offset,U8 sign,U8 * retV)
{
    static int s_fastpow_10[] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
    uint32_t tmp = s_fastpow_10[dotLen];
    uint8_t *p = retV, *dot;
    if (sign) {
        *p++ = '-';
    }
    p += sprintf((char *)p, "%d", value/s_fastpow_10[dotLen]);
    dot = p;
    *p++ = '.';
    while (tmp/10 > value) {
        *p++ = '0';
        tmp /= 10;
    }
    if (value) {
        p += sprintf((char *)p, "%d", value%s_fastpow_10[dotLen]);
    }
    *p = '\0';
    //oft = p - dot;
    if (decimalBit > 0) {
        dot[decimalBit+1] = '\0';
        for ( ; p < dot+decimalBit+1; ++p) {
            *p = '0';
        }
    } else {
        if (dotLen == 0) {
            *dot = '\0';
        }
    }
}
#define ABS(X)      ((X) < 0 ? (-(X)) : (X))
#define SIGN(X)     (((uint32_t)X) >> 31)

int main()
{
    U8 buf[32];
    DisplayFloatNum(ABS(-250), 0, 1, 1, SIGN(-250), buf);
    printf("%s\n", buf);

    return 0;
}
