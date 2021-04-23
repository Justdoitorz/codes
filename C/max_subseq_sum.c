#include <stdio.h>

int main()
{
    int value;
    scanf("%d", &value);
    printf("%s", (value&1) ? "odd" : "even");
}
