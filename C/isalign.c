#include <stdio.h>

#define IS_ALIGN(X, BASE)       (!((X) & ((BASE)-1)))

int main()
{
    int f;

    printf("%d\n", IS_ALIGN(1024*7+1, 1024));



    return 0;
}
