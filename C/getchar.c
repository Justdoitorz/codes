#include <stdio.h>

int main()
{
    char ch = 0;
    int i = 0;

    scanf("%d", &i);
    ch = getchar();

    printf("i = %d, ch = %d, ch = %c\n", i, ch, ch);
    return 0;
}
