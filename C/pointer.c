#include <stdio.h>

int main()
{
    char str[] = "WTFfffffff";
    char **p1 = 0;
    char ** const p2 = (char **)0;
    char * const *p3 = (char **)0;

    char const **p4 = (char **)0;
    char const*const*p5 = str;

    *p5 = 0;
    **p5 = 'w';

    return 0;
}
