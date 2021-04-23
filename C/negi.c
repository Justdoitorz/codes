#include <stdio.h>

// x ^ 0 = x
// x ^ 1 = ~x

int main()
{
    int n, i, s;

    scanf("%d", &n);
    n = ~n + 1;
    n = -n;
    printf("%d\n", n);
    return 0;
}
