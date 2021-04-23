#include <stdio.h>

int getStr1Str2(char *src, char *buf1, char *buf2)
{
    char *dst[2] = {buf1, buf2};
    int n = 0;
    while (*src) {
        *dst[n]++ = *src++;
        n ^= 1;
    }
    *dst[0] = '\0';
    *dst[1] = '\0';
    return 0;
}

int main()
{
    char *str = "1a2b3c4d5e6f7g";
    char buf1[64];
    char buf2[64];

    getStr1Str2(str, buf1, buf2);
    printf("buf1:%s\n", buf1);
    printf("buf2:%s\n", buf2);
    return 0;
}

