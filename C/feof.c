#include <stdio.h>

int
main()
{
    FILE *fp = fopen("TEST.txt", "rb+");

    char tmp;

    tmp = getc(fp);
    printf("tmp = %d\n", tmp);
    if (feof(fp)) {
        printf("File end\n");
    }

    fclose(fp);
    return 0;
}
