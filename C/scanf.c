#include <stdio.h>

int main()
{
    char a = 'a';
    int b = 1;
    float c = 1.;

    printf("%f\n", a + b + c);
    printf("%d\n", sizeof(a + b + c));
    return 0;
}
