#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printfs_utf8ToUnicode(unsigned char *str)
{
    unsigned char *uni = malloc(strlen(str)+1);
    unsigned char *p = uni;
    unsigned short val;

    while (*str) {
        if (*str < 0x80) {
            *p++ = *str++;
        } else {
            if (*str < 0xE0) {
                val = (*str++ & 0x3F) << 5;
                val |= (*str++ & 0x3F);
            } else {
                printf("*str & 0x0F = %x\n", *str & 0x0F);
                val = (*str++ & 0x0F) << 12;
                printf("*str & 0x3F = %x\n", *str & 0x3F);
                val |= (*str++ & 0x3F) << 6;
                printf("*str & 0x3F = %x\n", *str & 0x3F);
                val |= (*str++ & 0x3F);
            }
            //*(unsigned short *)p++ = val;
			*p++ = val & 0xff;
			*p++ = val >> 8;
            printf("val = %d\n", val);
        }
    }
    *p = '\0';
    printf("uni = %x\n", uni[0]);
    printf("uni = %x\n", uni[1]);
    printf("uni = %x\n", uni[2]);
    printf("uni = %x\n", uni[3]);
    return printf("%s\n", uni);
}


int main()
{
    unsigned char str[] = "中文";

    printf("%x\n", str[0]);
    printf("%x\n", str[1]);
    printf("%x\n", str[2]);

    printf("%x\n", str[3]);
    printf("%x\n", str[4]);
    printf("%x\n", str[5]);

    printf("%d\n", sizeof(str));
    printf("%s\n", str);
    printfs_utf8ToUnicode(str);
    return 0;
}
