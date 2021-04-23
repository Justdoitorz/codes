#include <stdio.h>

int _GCD(int m, int n)
{
    if (m % n == 0) {
        return n;
    } else {
        return _GCD(n, m%n);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    printf("%d\n", _GCD(m, n));
    return 0;
}
