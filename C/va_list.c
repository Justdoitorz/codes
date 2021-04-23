#include <stdio.h>
#include <stdarg.h>

int print_bin_32(int *addr)
{
    int i;
    for (i = 0; i < 32; ++i) {
        if (*addr & (1<<31-i)) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    putchar('\n');
    return 0;
}

typedef struct {
    float f;
    int a;
} St;

typedef float * Faddrt;

int va_func(int la, int num, ...)
{
    int *p = &num;
    va_list ap;
    va_start(ap, num);

    printf("%d\n", 6);
    print_bin_32(p++);
    print_bin_32(p++);
    printf("&num = %p\n", &num);
    printf("ap = %p\n", ap);
    printf("*ap = %d\n", *(int *)ap);
    char c = va_arg(ap, int);
    printf("ap = %p\n", ap);
    printf("first arg is:%d\n", c);
    printf("*ap = %d\n", *(int *)ap);
    print_bin_32(p++);
    print_bin_32(p++);

    short s = va_arg(ap, int);
    printf("second arg is:%d\n", s);
    print_bin_32(p++);
    print_bin_32(p++);
    int i = va_arg(ap, int);
    printf("third arg is:%d\n", i);
    print_bin_32(p++);
    print_bin_32(p++);
    long long ll = va_arg(ap, long long);
    printf("fourth arg is:%lld\n", ll);
    print_bin_32(p++);
    print_bin_32(p++);

    //print_bin_32(p++);

    double f = va_arg(ap, double);
    printf("fifth arg is:%f\n", f);
   // printf("fifth arg is:%f\n", *f);

    print_bin_32(p++);
    print_bin_32(p++);
    printf("ap = %p\n", ap);
    double d = va_arg(ap, double);
    printf("sixth arg is:%f\n", d);
    print_bin_32(p++);
    print_bin_32(p++);
    printf("ap = %p\n", ap);
    long double ld = va_arg(ap, long double);
    printf("ap = %p\n", ap);

    printf("seventh arg is: %Lf\n", ld);
    printf("p = %p\n", p);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);

    printf("p = %p\n", p);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);

    printf("*ap = %d\n", *(int *)ap);
    int i2 = va_arg(ap, int);
    printf("i2 = %d\n", i2);
    printf("ap = %p\n", ap);

    int i3 = va_arg(ap, int);
    printf("i3 = %d\n", i3);
    printf("ap = %p\n", ap);

    int i4 = va_arg(ap, int);
    printf("i3 = %d\n", i4);
    printf("ap = %p\n", ap);

    int i5 = va_arg(ap, int);
    printf("i3 = %d\n", i5);
    printf("ap = %p\n", ap);


    va_end(ap);
    return 0;
}

float print_float(float fsvsadffsd, float ggafafasdf)
{
    print_bin_32(&fsvsadffsd);
    print_bin_32(&ggafafasdf);
}

int main()
{
    char c = -1;
    short s = 2;
    int i = 4;
    long long ll = 0x1f0000000;



    long double ld = 1111111118.99999999;
    int *p = (int *)&ld;
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);
    print_bin_32(p++);


    printf("sizeof(long double) = %d\n", sizeof(long double));
    printf("ld = %Lf\n", ld);
    St t = {1, 2.0};

    float f = 1.3;
    double d = 1.3;

    if (f == d) {
        printf("f == d\n");
    }
    print_float(f, f);
    printf("f = %lf\n", f);

    int a = 0;
    printf("..%f\n", *(float *)&a);

    va_func(7, 3, c, s, i, ll, f, d, ld, i, i);

    return 0;
}
