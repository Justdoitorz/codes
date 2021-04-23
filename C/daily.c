#include <stdio.h>

int num = 0;
int value = 7;

int func(void)
{
    if
    (
    num
    ==
    0
    )
    return
    value
    +=
    1
    ;
    return
    5
    +
    7
    ;
}

int main()
{
    printf("%d\n", func());
    num = 1;
    printf("%d\n", func());
    return 0;
}
