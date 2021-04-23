#include <stdio.h>
#include <time.h>

int a[1024][2048];
int b[2048][1024];


void copy(int a[][2048], int b[][1024]) {
    int i, j;
    for (j = 0; j < 2048; ++j) {
    for (i = 0; i < 1024; ++i) {
           b[j][i] = a[i][j];
        }
    }

}

void copy_2(int a[][2048], int b[][1024]) {
    int i, j;
    for (i = 0; i < 2048; ++i) {
        for (j = 0; j < 1024; ++j) {
           b[i][j] = a[j][i];
        }
    }
}


int main()
{
    int i, j;
    clock_t begin, end;

    printf("sizeof = %d\n", sizeof(clock_t));
    begin = clock();
    for (i = 0; i < 1024; ++i) {
        for (j = 0; j < 2048; ++j) {
            a[i][j] = i*2048 + j;
        }
    }
    end = clock();

    printf("Use time: %d\n", end-begin);


    begin = clock();
    copy(a, b);
    end = clock();
    printf("Use time: %d\n", end-begin);

    printf("b[0][0] = %d\n", b[0][0]);
    printf("b[0][1] = %d\n", b[0][1]);
    printf("b[1][0] = %d\n", b[1][0]);
    printf("b[1][1] = %d\n", b[1][1]);

    begin = clock();
    copy_2(a, b);
    end = clock();
    printf("Use time: %d\n", end-begin);
    printf("b[0][0] = %d\n", b[0][0]);
    printf("b[0][1] = %d\n", b[0][1]);
    printf("b[1][0] = %d\n", b[1][0]);
    printf("b[1][1] = %d\n", b[1][1]);

    return 0;
}
