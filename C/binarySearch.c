#include <stdio.h>


int binarySearch(int *arr, int len, int target)
{
    int left = 0,right = len-1;

    while (left <= right) {
        int mid = (right+left)/2;
        if (arr[mid] < target) {
            left = mid+1;
        } else if (arr[mid] > target) {
            right = mid-1;
        } else {
            return mid;
        }
    }

    return -1;
}

int leftBound(int *arr, int len, int target)
{
    int left = 0,right = len-1;

    while (left <= right) {
        int mid = (right+left)/2;
        if (arr[mid] < target) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    if (left == len || arr[left] != target) {
        return -1;
    } else {
        return left;
    }
}

int rightBound(int *arr, int len, int target)
{
    int left = 0,right = len-1;

    while (left <= right) {
        int mid = (right+left)/2;
        if (arr[mid] <= target) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    if (left == 0 || arr[right] != target) {
        return -1;
    } else {
        return right;
    }
}

#define ARR_LEN(a) ((sizeof(a))/(sizeof(a[0])))

int main()
{
    int arr[] = {0, 0, 1, 3, 5, 5, 5, 6, 6, 7, 8};

    int find;

    find = binarySearch(arr, ARR_LEN(arr), 8);

    printf("%d\n", find);

    find = leftBound(arr, ARR_LEN(arr), 3);
    printf("%d\n", find);

    find = rightBound(arr, ARR_LEN(arr), 2);
    printf("%d\n", find);

    return 0;
}
