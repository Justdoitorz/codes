#include <stdio.h>

__attribute__((cdecl)) int g(int a, int b) 
{
    printf("a = %d, b = %d\n", a, b);
    return a+b;
}

int main(void)
{
  
    g(1, 2);

    return 0;
}
