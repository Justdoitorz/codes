#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[160];
    //int i = 0;
    //volatile int * volatile p = &i;
    FILE *fp = fopen("fread.c", "rb");
    size_t len;

    while (len = fread(buf, 1, 16, fp)) {
        //;
        //fgets(buf, 16, fp);

        for (int i = 0; i < len; i++)
          putchar(buf[i]);

        //if (feof(fp)) {
        //    exit(-1);
        //}
        printf("len = %d\n", len);

        //printf("%s", buf);
    }
    printf("len = %d\n", len);

    fclose(fp);
    return 0;
}
