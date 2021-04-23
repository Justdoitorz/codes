#include <stdio.h>
#include <math.h>
#include <time.h>

int isprime(long long n)
{
    long long i, max;
    //printf("n = %I64d\n", n);
    if (n == 2 || n == 3) {
        return 1;
    }

    if ((n%6 != 1) && (n%6 != 5)) return 0;

    max = sqrt(n);
    //printf("max = %I64d\n", max);
    for (i = 6; i <= max; i += 6) {
        if (n%(i-1) == 0 || n%(i+1) == 0){
            return 0;
        }
    }
    return 1;
}

int prime[1024] = {
    2, 3,
};

void init_prime(void)
{
    int i = 6, pos = 2;
    while (pos < 1024) {
        if (isprime(i-1)) {
            prime[pos++] = i-1;
        }

        if (isprime(i+1)) {
            prime[pos++] = i+1;
        }
        i += 6;
    }
}


long long func(long long n)
{

    #if 1
    int pos = 0;
    while (!isprime(n)) {
        if (n % prime[pos] == 0) {
            n /= prime[pos];
        } else {
            pos++;
        }
       // printf("pos = %d\n", pos);
    }
    return n;
    #else
    int pos = 1023;
    while (n%prime[pos] != 0) {
        pos--;
    }
    return prime[pos];
    #endif


}

int main()
{
    long long ret;
    clock_t start, end;
    start = clock();
    init_prime();

    //printf("wtf\n");
   // printf("...%d\n", isprime(127));

    ret = func(600851475143);
    printf("ret = %I64d\n", ret);
    end = clock();

    printf("start = %ld\n", start);
    printf("end = %ld\n", end);
    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);

    return 0;
}
