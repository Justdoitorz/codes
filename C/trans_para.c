#include <stdio.h>
#include <stdarg.h>

int cacl_sum(int cnt, ...)
{
    int sum = 0;
    va_list va;
    va_start(va, cnt);
    for (int i = 0; i < cnt; i++) {
        sum += va_arg(va, int);
    }
    va_end(va);
    return sum;
}
int print(int a)
{
    printf("return %d;\n", a);
    return a;
}

int func(int a, int b)
{
    return a+b;
}

int func_m(int a, int b, int c, int d, int e, int f, int g)
{
    return a+b+c+d+e+f+g;
}

int main()
{
    printf("func(1, 2) = %d\r\n", func(print(1), print(2)));

    printf("cacl_sum(4, 1, 2, 3, 4) = %d\n", cacl_sum(print(4), print(1), print(2), print(3), print(4)));

    printf("func_m(1, 2, 3, 4, 5, 6, 7) = %d\r\n", func_m(1, 2, 3, 4, 5, 6, 7));
    return 0;
}
