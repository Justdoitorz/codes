#include <stdio.h>

#define ARR_LEN(arr)        (sizeof(arr)/sizeof(arr[0]))

int max(int a, int b, int c)
{
    if (a > b && a > c) {
        return a;
    } else if (b > a && b > c) {
        return b;
    } else {
        return c;
    }
}

int findMaxCorssSubArray(int *arr, int low, int mid, int high)
{
    int leftsum = 0xc0000000, rightsum = 0xc0000000, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftsum) {
            leftsum = sum;
        }
    }

    sum = 0;
    for (int j = mid+1; j <= high; j++) {
        sum += arr[j];
        if (sum > rightsum) {
            rightsum = sum;
        }
    }
    printf("left:%d, right:%d\n", leftsum, rightsum);
    return leftsum+rightsum;
}

int findMaximumSubArray(int *arr, int low, int high)
{
    if (low == high) {
        return arr[low];
    } else {
        int mid = (low+high)>>1;
        int leftsum = findMaximumSubArray(arr, low, mid);
        int rightsum = findMaximumSubArray(arr, mid+1, high);
        int midsum = findMaxCorssSubArray(arr, low, mid, high);

        return max(leftsum, rightsum, midsum);
    }
}


int main()
{
    int arr[] = {-10, -11, -21, -3, -8, -5, -6};
    printf("maxsub sum = %d\n", findMaximumSubArray(arr, 0, -1));

    return 0;
}
