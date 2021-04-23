#include <stdio.h>

int foo(int a, int b)
{
    return a-b;
}

int func(int a, int b, int foo(int, int))
{
    return foo(a, b);
}


int add(int a, int b)
{
    return a+b;
}

typedef unsigned long long      uint64_t;

int main()
{
    int a = (unsigned int)-1;
    printf("%d\n", a);
    printf("%I64d\n", (((uint64_t)1<<32)-1));
    printf("%I64d\n", (~((uint64_t)-1<<32)));
    return 0;
}
