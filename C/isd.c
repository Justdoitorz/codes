#include <stdio.h>

int main()
{
    FILE *fr, *fw;
    fr = fopen("bak.v", "rb");
    fw = fopen("out.txt", "w+");

    char buf[16];
    int i = 0;
    while (1) {
        unsigned char r;

        fread(&r, 1, 1, fr);
        if (feof(fr)) {
            break;
        }

        sprintf(buf, "0x%02X,", r);

        fwrite(buf, 1, 5, fw);
        i++;
        if (i % 16 == 0) {
            fwrite("\n", 1, 1, fw);
        }
    }

    fclose(fr);
    fclose(fw);
    return 0;
}
