#include <stdio.h>

typedef enum {
    false,
    true,
}ENUM;

void func(double a, double f, double d)
{
    printf("a = %f, f = %f, d = %f\n", a, f, d);
}

int main()
{
    int a = 1024;
    float f = 1.25;
    double d = 0.125;
    func(a, f, d);

    printf("f = %f, d = %f\n", f, d);

    printf("sizeof(ENUM) = %i\n", sizeof(ENUM));

    return 0;
}
