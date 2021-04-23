#include <stdio.h>

long long quick_power(int base, int power)
{
    long long ret = 1;
    long long b = base;
    long long n = power;
    while (n) {
        if (n & 1) {
            ret *= b;
        }
        b *= b;
        n >>= 1;
    }

    return ret;
}

int main()
{
    printf("%I64d\n", quick_power(2, 33));
    return 0;
}
