#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    float f = 0.1;
    float g = 1.1;


    int a;
    int b;
    memcpy(&a, &f, 4);
    memcpy(&b, &g, 4);
    printf("%x\n", a);
    printf("%x\n", b);

    if (f < g) {
        printf("f < g\n");
    }

    return 0;
}
