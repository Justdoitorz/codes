#include <stdio.h>

int func(int a, int b)
{
    int c = 3;
    b = 4;
    a = 5;
    return a+b+c;
}

int main()
{
    int a = 1;

    a = func(a, 2);

    return 0;
}
