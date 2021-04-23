#include <stdio.h>
#include <string.h>

int arr[64][128][1024];

void func(void)
{
    int i, j, k;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 128; j++) {
            for (k = 0; k < 1024; k++) {
                ;//arr[i][j][k] = 0;
            }
        }
    }
}

void func_2(void)
{
    int i, j, k;
    for (i = 0; i < 64; i++) {
        for (k = 0; k < 1024; k++) {
            for (j = 0; j < 128; j++) {
                ;//arr[i][j][k] = 0;
            }
        }
    }
}

void func_3(void)
{
    int *st = &arr[0][0][0];
    int *end = st + 64*128*1024;
    for (; st < end; st++) {
        *st = 0;
        //st++;
    }
}

int main()
{
    func_3();

    return 0;
}
