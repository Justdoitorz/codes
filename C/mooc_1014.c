#include <stdio.h>

int main()
{
    int num, sum = 1, times = -1;

    do {
        scanf("%d", &num);
        times++;
        sum += num;
    } while (num != -1);

    printf("%d\n%f\n", times, (float)sum/times);
    return 0;
}
