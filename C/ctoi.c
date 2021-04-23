#include <stdio.h>

// 1 3 10
// 0 1 6
unsigned int func (unsigned int n)
{
    unsigned int up = 1, down = 0, tmp;

    while (n--) {
        tmp = up;
        up =(up * 3 + down)%1000000007;
        down = (down * 3 + tmp)%1000000007;
    }
    return up;
}

int main()
{
    unsigned int r, n;
    scanf("%d", &n);
    r = func(n);
    printf("%u\n", r);
    return 0;
}
