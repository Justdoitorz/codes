#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a = malloc(1024);
    double d = 0.0;
    free(a);
    free(a);
    //a = 0;
    //*a = 10240;
    printf("%f\n", 1024/d);
    return 0;
}
