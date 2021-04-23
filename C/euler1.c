#include <stdio.h>
#include <assert.h>

int calcEqualAberration(int a0, int an, int n)
{
    return n*(a0+an)>>1;
}

int func(int n)
{
    assert(n > 0);
    int sum = 0;
    n--;
    sum += calcEqualAberration(3, n/3*3, n/3);
    sum += calcEqualAberration(5, n/5*5, n/5);
    sum -= calcEqualAberration(15, n/15*15, n/15);
    return sum;
}

int main()
{
    int sum;
    sum = func(0);
    printf("%d\n", sum);
    return 0;
}
