#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN(arr)        (sizeof(arr)/sizeof(arr[0]))

int min(int x, int y)
{
    return x < y ? x : y;
}

void merge_sort(int *arr, int len)
{
    int *buf = (int *)malloc(sizeof(int) * len);
    int *src, *dst = arr;
    int seg, start;
    for (seg = 1; seg < len; seg <<= 1) {
        src = dst;
        dst = dst==arr ? buf : arr;
        for (start = 0; start < len; start += seg<<1) {
            int low = start, mid = min(start+seg, len), high = min(start+seg+seg, len);
            int idx = low, L = low, LE = mid, R = mid, RE = high;

            while (L < LE && R < RE) {
                dst[low++] = src[L] <  src[R] ? src[L++] : src[R++];
            }

            while (L < LE) {
                dst[low++] = src[L++];
            }
            while (R < RE) {
                dst[low++] = src[R++];
            }
        }
    }

    if (dst != arr) {
        for (int i = 0; i < len; i++) {
            arr[i] = dst[i];
        }
    }
    free(buf);
}

void show_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {3, 1, 4, 2, 6, 7, 0, 5, 8, -7};
    printf("Original:\n");
    show_arr(arr, ARR_LEN(arr));
    merge_sort(arr, ARR_LEN(arr));
    printf("After sort:\n");
    show_arr(arr, ARR_LEN(arr));

}
