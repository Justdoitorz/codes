#include <stdio.h>
char result[32];
int main()
{
    int n = 195132894;
    int idx = 0, remainder;

    //scanf("%d", &n);
    while (n) {
        remainder = (n % 7 + 7) % 7;
        result[idx++] = remainder + '0';
        n -= remainder;
        n /= -7;
    }
    for (--idx; idx >= 0; --idx) {
        putchar(result[idx]);
    }
    return 0;
}
