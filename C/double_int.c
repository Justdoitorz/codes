#include <stdio.h>

int main()
{
    int i;
    int num3, num4, flag;

    for (i = 18; i < 22; ++i) {
        num3 = i*i*i;
        num4 = num3*i;

        flag = 0x3ff;
        if (num4 >= 102345 && num4 <= 987654) {
            while (num3) {
                flag ^= 1<<(num3%10);
                num3 /= 10;
            }
            while (num4) {
                flag ^= 1<<(num4%10);
                num4 /= 10;
            }
            if (!flag) {
                printf("age=%d\n", i);
                break;
            }
        }

    }

    return 0;
}
