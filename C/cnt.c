#include <stdio.h>

int main()
{
    int cnt = 0;
    char c;

    while (scanf("%c", &c) != EOF) {
        printf("c = %d\n", c);
        if (c == '\n') {
            ++cnt;
        }
    }

    printf("cnt = %d\n", cnt);

    return 0;
}
