#include <stdio.h>
#define ABS(X)      (((X)< 0)?(-(X)):(X))
#define DISTANCE(A, B)   ABS(((A)-(B)))
int matrix[20][20];
int main()
{
    int x, times, n, i, j, dir = 1, num = 1;
    scanf("%d", &n);
    for (i = 0; i < 2*n-1; i++) {
        x = (i&1) ?  i : 0;
        times = n - DISTANCE(i+1, n);//(i < n) ? i+1 : 2*n-(i+1);
        //x = (i < n) ? x : x + dir*(i+1-n);
        //x += (i < n) ? 0 : dir*(i+1-n);
        if (i >= n) {
            x += dir*(i+1-n);
        }
        for (; times; times--, x += dir) {
            matrix[i-x][x] = num++;
        }
        dir = -dir;
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
