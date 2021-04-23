#include <stdio.h>

int main()
{
    char buf[] = "Hello", *p = buf;

    printf("%c\n", ++p[0]);

    return 0;
}
