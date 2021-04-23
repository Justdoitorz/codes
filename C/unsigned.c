#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, r;
    int k;

    scanf("%lf%lf", &a, &b);

    printf("%f", a-b*((int)(a/b)));
    return 0;
}
