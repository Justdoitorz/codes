#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[4*1024*1024*5];
char outbuf[4*1024*1024*8];

int main()
{
    FILE *fps, *fpd;
    int cnt = 0;
    int i, length;
    //char buf[4096*5], outbuf[8*4096];
    char outname[16];
    int sidx, didx;

    fps = fopen("zb229a_picdata.txt", "rb+");

    while (length = fread(buf, sizeof(char), 4*1024*1024*5, fps)) {
        printf("length = %d\n", length);
        sprintf(outname, "dest%d.txt", cnt++);

        printf("%s\n", outname);
        fpd = fopen(outname, "wb+");
        didx = sidx = 0;
        for (int i = 0; i < (length/256)/5; i++) {
            memcpy(outbuf+didx, buf+sidx, 256*5);
            didx += 256*5;
            sidx += 256*5;
            outbuf[didx++] = '\n';
            outbuf[didx++] = '\n';

        }

        fwrite(outbuf, sizeof(char), didx, fpd);
        fclose(fpd);

    }

    printf("byebye\n");

    return 0;
}
