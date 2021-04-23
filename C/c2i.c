#include <stdio.h>

int main()
{
    char arr[100];
    int a[3][7] = {
        {0, 1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12, 13,},
        {14, 15, 16, 17, 18, 19, 20},
    };
    int i;
    for (i = 0; i < 100; i++) {
        arr[i] = i;
    }


    int *p = (int *)arr;
    for (i = 0; i < 25; i++) {
        if (p[i] <= 100) {
            printf("hp = %d, addr = %p\t", p[i], p+i);
        }
        //printf("%#010x\n", p[i]);
    }

    printf("\n%d\n", *(a+1)[5]);//p[i] = *(p+i); *(a+1)[5] = *(*((a+1) + 5));
    printf("%d\n", *(*a+3));
    printf("%d\n", *(*(a+1)));
}
