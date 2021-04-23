#include <stdio.h>

int print(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; ++i) {
        printf("i = %d : %d\n", i, nums[i]);
    }
    return 0;
}

int removeDuplicates_(int* nums, int numsSize)
{
	int cnt = 1;
	int *new_pos = nums+1, *last = nums;
    printf("numsSize = %d\n", numsSize);
	if (!numsSize) return numsSize;

	while (--numsSize) {
		if (*last != *new_pos) {

			++cnt;
			*++last = *new_pos;
		}
		++new_pos;
	}

    printf("cnt = %d\n", cnt);
	return cnt;
}

int removeDuplicates(int* nums, int numsSize)
{
	int cnt = 0, value = nums[0] - 127;
	int *new_pos = nums, *last = &value;

    //print(nums, numsSize);

   // printf("numsSize = %d\n", numsSize);
	while (numsSize--) {
       // printf("*new_pos = %d\n", *new_pos);
		if (*last != *new_pos) {
			last = &nums[cnt];
			nums[cnt++] = *new_pos;
		}
		new_pos++;
	}

    printf("cnt = %d\n", cnt);
	return cnt;
}

int main()
{
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    //printf("%d\n", removeDuplicates(nums, 10));
    print(nums, removeDuplicates_(nums, 10));

    return 0;
}
