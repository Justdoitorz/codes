#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[] = "\000\x1234567800";
    float f = -1023.0;
    int a;
    unsigned x = 42, y = 10;
    printf("%d, %d\n", sizeof(int), sizeof(float));
    memcpy(&a, &f, sizeof(f));

    printf("%x\n", a);
    //bf400000
    //1 011 1111 0 100 0000 0000 0000 0000 0000
    printf("f'addr = %p\n", &f);
    printf("%f\n", f);

    //system("pause");
    printf("%f\n", f);

    printf("%u\n", y-x);
    printf("%d\n", sizeof(c));
    printf("c[1] = %d\n", c[1]);
    return 0;
}
