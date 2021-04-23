#include <stdio.h>

float fun(double h)
{
    float f;
    char buf[1024];
    sprintf(buf, "%.2f", h);
    sscanf(buf, "%f", &f);
    return f;
}

float fun_f(float h)
{
    float f;
    int s = (h * 100 + 0.5);
    f = s*0.01;
    return f;
}

int main()
{
    double d;
    float f;

    scanf("%lf", &d);
    printf("...%%2lf = %.2lf\n", d);
    f = fun(d);
    printf("%.6f\n", f);

    scanf("%f", &f);
     printf("...%%2f = %.2f\n", f);
    f = fun_f(f);
    printf("%.6f\n", f);

    return 0;
}
