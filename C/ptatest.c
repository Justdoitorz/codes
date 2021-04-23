#include <stdio.h>
#include <string.h>

void deal(char *buf)
{
    int tail = strlen(buf);
    int dl = tail - (buf[0] == '-');
    int insertnum = (dl-1)/3;
    int i;
    while (insertnum) {
        for (i = 2; i >= 0; i--) {
            buf[tail-3+i+insertnum] = buf[tail-3+i];
        }

        buf[tail+insertnum-4] = ',';
        tail = tail-3;
        insertnum--;
    }
}

int main()
{
    int a, b;
    char buf[64];
    memset(buf, 0, 64);
    scanf("%d%d", &a, &b);
    sprintf(buf, "%d", a+b);
    deal(buf);

    printf("%s", buf);
    return 0;
}
