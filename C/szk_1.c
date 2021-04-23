#include <stdio.h>



void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void szk_print_arr(const char *msg, int *arr, int len)
{
    printf("%s ", msg);
    for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// 堆排序：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆。
void max_heapify(int arr[], int start, int end) {
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子节点在范围内才做比较
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点指标，选择最大的
			son++;
		if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完成，直接跳出函数
			return;
		else { //否则交换父子內容再继续子节点与孙节点比較
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void szk_heap_sort(int arr[], int len) {
	//初始化，i从最后一个父节点开始调整
	for (int i = len / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, len - 1);
		szk_print_arr("中间0:", arr, len);
	}
	//先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完成
	for (int i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
		szk_print_arr("中间1:", arr, len);
	}
}



int main() {
	int arr[] = { 3, 15, 233, 20, 8, 36, 11, 45, 888, 56, 2, 74, 9, 64, 7, 80, 1, 98, 1239, 117, 683, 191, 882, 5, 109, 777, 14, 0, 22, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	szk_heap_sort(arr, len);
    szk_print_arr("最终:", arr, len);
	return 0;
}
