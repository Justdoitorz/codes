#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ABS(X)   ((X<0) ? -(X) : X)

int force[100000];

int comp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}


int leftBound(int *arr, int len, int target)
{
    int left = 0,right = len-1, mid;
    while (left <= right) {
        mid = (right+left)/2;
        if (arr[mid] == target) {
            right = mid-1;
        } else if (arr[mid] < target) {
            left = mid+1;
        } else if (arr[mid] > target) {
            right = mid-1;
        }
    }
    return left;
}

int main()
{
    int n, me, cnt = 0, min, max;

    scanf("%d%d", &n, &me);

    for (int i = 0; i < n; i++) {
        scanf("%d", force+i);
    }

    qsort(force, n, sizeof(int), comp);


    for (int i = 0; i < n; i++) {
        //printf("%d\n", force[i]);
    }

    for (int i = 0; i < n-1; i++) {
        min = ABS(me-force[i]);
        max = me+force[i];
        //printf("range:(%d, %d)\n", min, max);
        min = leftBound(force+i+1, n-i-1, min+1);
        max = leftBound(force+i+1, n-i-1, max);

        //printf("min = %d\t", min);
        //printf("max = %d\n", max);
        cnt += max-min;
    }


    printf("%d\n", cnt);
    return 0;
}
