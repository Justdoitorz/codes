#include <stdio.h>

#define _SIMD(addr)   (*(int **) &(addr))

#define _SIMDEX(addr)       (int *)(addr)

int main()
{
    short *a = 0;

    _SIMD(a)++;
    printf("%p\n", a);

    _SIMDEX(a)++;
    printf("%p\n", a);

    return 0;
}
