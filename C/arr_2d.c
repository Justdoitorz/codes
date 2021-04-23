#include <stdio.h>

typedef int arr4[4];

int main()
{
    int ((arr[3])[4]) = {
        {0, 1, 2, 3,},
        {999, 5, 6, 7,},
        {8, 9, 10, 11,},
    };

    int a = arr[0][1];   int b = *(*(arr+0) + 1);
    int *p = &arr[0][1]; int *q = (*(arr+0) + 1);
    int *r = arr[0];     int *t = *(arr+0);
    int (*ap)[4] = &arr[1];  int (*bp)[4] = (arr+1);
    int (*cp)[4] = arr;
    int ((*dp)[3])[4] = &arr;
    return 0;
}
