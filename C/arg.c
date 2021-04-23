#include <stdio.h>
#include <stdarg.h>

int func(int num, ...)
{
    va_list ap;
    va_start(ap, num);

    char c = (char)va_arg(ap, int);
    printf("%c\n", c);

    short s = (short)va_arg(ap, int);
    printf("%d\n", s);

    int i = va_arg(ap, int);
    printf("%d\n", i);

    float f = (float)va_arg(ap, double);
    printf("%f\n", f);

    double d = (double)va_arg(ap, double);
    printf("%lf\n", d);

    va_end(ap);
    return 0;
}

int main()
{
    func(4, 'a', 256, 65536, 1.1, 1.1368922);
    return 0;
}
