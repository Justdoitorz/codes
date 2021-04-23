#include <stdio.h>


int main()
{
    char buff[1024];
    FILE *fp = fopen("MeterLogic.txt", "rb");
    if (NULL == fp) {
        printf("fopen error\n");
        exit(1);
    }


    fgets(fp,)


}
