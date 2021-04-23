#include <stdio.h>

#define ARR_LEN(arr)        (sizeof(arr)/sizeof(arr[0]))

void insertion_sort(int *arr, int len)
{
    int i, j;
    for (i = 1; i < len; i++) {
        int key = arr[i];
        for (j = i; j > 0 && arr[j-1] > key; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }
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
    int arr[] = {3, 1, 4, 2, 6, 7, 0};
    printf("Original:\n");
    show_arr(arr, ARR_LEN(arr));
    insertion_sort(arr, ARR_LEN(arr));
    printf("After sort:\n");
    show_arr(arr, ARR_LEN(arr));

}
