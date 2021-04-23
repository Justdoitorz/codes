#include <stdio.h>
#include <string.h>

int main()
{
    int num, sum = 0, val[5], i;
    scanf("%d", &num);
    for (i = 0; i < 5; ++i) {
        val[i] = num%10;
        num /=10;
        sum += val[i];
    }
    printf("%d(%d+%d+%d+%d+%d=%d)", sum, val[4], val[3], val[2], val[1], val[0], sum);

    return 0;
}
