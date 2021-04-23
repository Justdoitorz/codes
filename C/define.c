#include         <stdio.h>
double func(double r);
int main()
{
    #define PI 3.141592654

    double r;

    scanf("%lf", &r);
    printf("%f\n", func(r));
    return 0;
}

double func(double r)
{
    return 2.0*PI*r;
}
