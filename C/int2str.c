#include <stdio.h>

int main()
{
    unsigned char *p;
    int num = 0x12345678;
    int *pint = &num;
    int i;
    p = (unsigned char *)pint;

    for (i = 0; i < 4; i++) {
        printf("0x%2x\t", p[i]);
    }

    return 0;
}
