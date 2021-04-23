#include <stdio.h>

int func(int n, int number)
{
    return (n-1)/10;
}

int main()
{
    int n, tmp, num;
    int sum = 0;
    int weight = 1;
    int mod = 0;


    scanf("%d%d", &n, &num);
    tmp = n;
    while (tmp) {
        mod = tmp % 10;

        if (mod > num) {
            sum += weight;
        } else if (mod == num) {
            sum += n%weight + 1;
        }
        tmp /= 10;
        sum += tmp * weight;
        weight *= 10;

        printf("sum = %d\n", sum);
    }

    printf("%d\n", sum);
    return 0;
}
