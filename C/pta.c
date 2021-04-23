#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int ArrayShift( int a[], int n, int m )
{
    int *tmp = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        tmp[i] = a[n-m+i];
    }

    for (int i = n-1; i >= m; i--) {
        a[i] = a[i-m];
    }

    memcpy(a, tmp, m*sizeof(int));

    free(tmp);
    return 0;
}
