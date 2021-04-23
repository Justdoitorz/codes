#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    float f = .0;
    printf("please Input:");
    printf("first..%d\n", scanf("%d%d", &a, &b));
    printf("a: %d, b: %d\n", a, b);
    printf("second...%d\n", scanf("%d%d", &a, &b));
    printf("a: %d, b: %d\n", a, b);

    scanf("%f", &f);
    printf("%f\n", f);

    printf("hello");
    return 0;
}
