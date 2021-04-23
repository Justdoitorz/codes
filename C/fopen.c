#include <stdio.h>
#include <windows.h>

int main()
{
    char buff[1024];
    FILE *fp = fopen("utf-8.txt", "rb+");

    fseek(fp, 0, SEEK_SET);

    fputc('F', fp);

    fclose(fp);
    return 0;
}
