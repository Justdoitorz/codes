#include <stdio.h>

int main()
{
    long long a, b, c;
    int n, i;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);

        if (a>0 && b >0 && a+b<0) {
            printf("case #%d: true\n", i);
        } else if (a<0 && b<0 && a+b>=0) {
            printf("case #%d: false\n", i);
        } else if (a+b>c) {
            printf("case #%d: true\n", i);
        } else {
            printf("case #%d: false\n", i);
        }

    }

    return 0;
}
