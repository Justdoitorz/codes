#include <stdio.h>
#include <string.h>

int main()
{
    char a;
    char arr[] = "hello world!";
    char *p = "hello";
    char *p1 = "world";
    //strcpy(p, p1);
    //strcpy(p, p+1);
    strcpy(arr+6, arr);

    putchar(a);
    printf("&a = %p\n", &a);
    printf("p = %p\n", p);
    puts(&a);

    //puts(p);
    printf("p");
    return 0;
}
