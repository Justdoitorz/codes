#include <stdio.h>
#include <string.h>

char *strcat_p(char *dest,const char *src)
{
     char *t=dest;
     while(*t)  t++;
     int n=0;
    const char *temp=src;
    while(*src) n++, src++;
    while(n--) *t++=*temp++;
   *t='\0';
   return  dest;
}
int main()
{
    char str[32] = "Hello world!!!";
    char *dest, *src, *p;
    p = strcat_p(str+2, str);
    printf("%s\n", str);

    return 0;
}
