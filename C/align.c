#include <stdio.h>

#define ALIGN_X(X, BASE)        (X& -(BASE))
#define ALIGN_UP(X, BASE)        (((X)+(BASE)-1) & ~((BASE)-1))//+&
#define ALIGN_UP_2(X, BASE)        (-(-(X)&-(BASE)))//-&-
int main()
{
    printf("%d\n", ALIGN_X(6, 3));
    printf("%d\n", ALIGN_UP_2(4098, 4096));
    return 0;
}
