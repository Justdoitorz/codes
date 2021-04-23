#include <stdio.h>

int main()
{
    char buf[256];
    int a, b, c, d;
    scanf("%s", buf);
    printf("IP: %s\n", buf);

    sscanf(buf, "%d.%d.%d.%d", &a, &b, &c, &d);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);


    return 0;
}
