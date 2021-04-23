#include <stdio.h>

typedef union {
    int i;
    float f;
}IntFloat_u;

int main()
{
    IntFloat_u u;
    u.f = 0.07525;

    printf("%f\n", u.f);
    printf("%d\n", u.i);
    return 0;
}
