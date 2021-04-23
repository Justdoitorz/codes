#include <stdio.h>
#include <math.h>

int main()
{
    long long ll;

    int n, i;
    scanf("%d", &n);
    //ll = n;
    ll = pow(n, n);
    printf("%I64d\n", ll);
    for (i = 1; i <= n-1; ++i) {
        n *= n;
    }
    printf("%d\n", n);
    return 0;
}
