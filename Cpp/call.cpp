#include <iostream>

__attribute__((cdecl))
int foo(int a, int b)
{
	return a+b;
}
__attribute__((stdcall))
int  bar(int a, int b)
{
    return a-b;
}

int main()
{
    
    int f = foo(1, 2);
    int b = bar(1, 2);
    return 0;
}

