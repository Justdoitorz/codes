#include <stdio.h>

int main()
{
    char (*p)[6];
    char arr[6] = "Hello";
    int len;
    p = &arr;
    len = (int)(p+1) - (int)p;
    printf("%d\n", len);
    printf("%p\n", p+1);
    printf("%p\n", p);



    return 0;
}
