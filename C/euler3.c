#include <stdio.h>
#include <math.h>

int isprime(long long n)
{
    long long  max;
    if (n == 2 || n == 3) {
        return 1;
    }

    if (n%6 != 1 || n%6 != 5) return 0;

    max = sqrt(n);
    for (int i = 6; i <= max; i += 6) {
        if (n%(i-1) == 0 || n%(i+1) == 0){
            return 0;
        }
    }
    return 1;
}

int prime[] = {
    2, 3, 5, 7, 11, 13, 17, 19,
    23, 29, 31, 37, 41, 43, 47, 53,
    59, 61, 67, 71, 73, 79, 83, 89,
    97, 101, 103, 107, 109, 113, 127,
};

long long func(long long n)
{
    int pos = 0;
    while (!isprime(n)) {
        if (n % prime[pos] == 0) {
            n /= prime[pos];
        } else {
            pos++;
        }
        printf("pos = %d\n", pos);
    }

    return n > prime[pos-1] ? n : prime[pos-1];
}

int main()
{
    long long ret;

    ret = func(13195);

    printf("...%d\n", isprime(2));
    printf("ret = %I64d\n", ret);

    return 0;
}
