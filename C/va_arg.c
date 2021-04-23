#include <stdio.h>

const char *func(const char *in, const char *two, int a, int b)
{
    printf("%s\n", in);
    printf("%s", two);
    printf("a = %d, b = %d\n", a, b);

    return "c...";
}


int main()
{
    printf("a ... = %s, , %d, %c, %f, %d, %d, %d, %d, %d\n", func("b...", "sb...", 9, 0), 1, 'g', 1.11, 2, 3, 4, 5, 6);

    puts("dddd");
    puts("mdzz\n");
    puts("hello");
    return 0;
}
