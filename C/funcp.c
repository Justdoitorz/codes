#include <stdio.h>

typedef int (*pfunc)(int);

int main()
{
    int (*p)(int) = (int (*)(int))0x1234;
    p = (pfunc)0x5678;
    return 0;
}
