#include <stdio.h>

int main()
{
    unsigned char str[] = "\xD6\xD0\xCe\xC4";
    printf("str = %x\n", str[0]);
    printf("str = %x\n", str[1]);
    printf("str = %x\n", str[2]);
    printf("str = %x\n", str[3]);
    printf("%s\n", str);
    return 0;
}
