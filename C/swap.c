#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long long fast_pow(long long base, int n)
{
    long long ret = 1;
    while (n) {
        if (n & 1) {
            ret *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ret;
}

int my_sqrt(int num)
{
    long long left = 1, right = num, mid, pow;

    while (left <= right) {
        mid = (left + right)>>1;
        pow = mid*mid;
        //pow = fast_pow(mid, 2);
       // printf("%I64d...\n", pow);

        if (pow == num) return mid;
        else if (pow < num) left = mid+1;
        else right = mid-1;
    }

    return right;
}

int _sqrt(int x)
{
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return (int)res;
}

float InvSqrt(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating VALUE
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    return 1/x;
}

int isprime_1(int num)
{
    if (num <= 3) {
        return num > 1;
    }

    if (num%6&3^1) {
        return 0;
    }

    int i, n;
    n = my_sqrt(num);
    for ( i = 5; i <= n; i += 6) {
        if (!(num%i) || !(num%(i+2))) {
            return 0;
        }
    }
    return 1;
}

int isprime_2(int num)
{
    if (num <= 3) {
        return num > 1;
    }

    int i, n;
    n = sqrt(num);
    for (i = 2; i <= n; ++i) {
        if (!(num%i)) {
            return 0;
        }
    }
    return 1;
}

int isprime_3(int num)
{
    if (num <= 3) {
        return num > 1;
    }

    int i;
    for (i = 2; i < num; ++i) {
        if (!(num%i)) {
            return 0;
        }
    }
    return 1;
}

void test_sqrt(void)
{
    int i;
    for (i = 0x7ff00000; i < 0x7fffffff; ++i) {
        if (my_sqrt(i) * my_sqrt(i) == i) {
            printf("Error %d ...my_sqrt(i) = %d\n", i, my_sqrt(i));
            //exit(1);
        }
        //printf("Test: sqrt(%d) = %d\n", i, my_sqrt(i));
    }
}

int main()
{
    int i, cnt = 0;
    printf("%d\n", my_sqrt(100000000));
    test_sqrt();

    for (i = 999990000; i < 1000000000; ++i) {
        if (isprime_1(14407*14407)) {
            printf("%d\n", i);
            ++cnt;
        }
    }

    printf("cnt = %d\n", cnt);

    return 0;
}
