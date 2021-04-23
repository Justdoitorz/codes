#include <stdio.h>
int i = 0;

void func(char *a)
{
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    printf("%p\n", str);
    printf("%s\n", str);
}

void func2(char *a)
{
    char str[64];
    printf("%p\n", str);
    for (i = 0; i < 64; i++) {
        printf("%c", str[i]);
    }
}
int main()
{
    char str[16] = "hnshnshnshnshns";
    func(str);
    func2(str);
    return 0;
}
