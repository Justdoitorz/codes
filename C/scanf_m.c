#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%3d%4d%*2d%3d", &a, &b, &c);

    printf("��ѧ��ݣ�%d\n", b);
    printf("ѧԺ���룺%d\n", a);
    printf("�༶���ţ�%03d\n", c);

    return 0;
}
