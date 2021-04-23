#include <stdio.h>
#include <math.h>


int main()
{
    int fib[1024] = {1, 2, }, sum = 2, i;

    for (i = 2; i < 1024; i += 3) {

        fib[i+1] = 2*fib[i-1] + fib[i-2];
        fib[i+2] = 3*fib[i-1] + 2*fib[i-2];
        if (fib[i+2] > 4000000) {
            break;
        }
        sum += fib[i+2];
    }

    printf("%d\n", sum);
}
