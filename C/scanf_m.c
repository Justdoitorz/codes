#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%3d%4d%*2d%3d", &a, &b, &c);

    printf("入学年份：%d\n", b);
    printf("学院代码：%d\n", a);
    printf("班级座号：%03d\n", c);

    return 0;
}
