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
// �����򣺣����ѣ������������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ��ѡ�
void max_heapify(int arr[], int start, int end) {
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //���ӽڵ��ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ�ָ�꣬ѡ������
			son++;
		if (arr[dad] > arr[son]) //������ڵ�����ӽڵ���������ɣ�ֱ����������
			return;
		else { //���򽻻����Ӄ����ټ����ӽڵ�����ڵ���^
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void szk_heap_sort(int arr[], int len) {
	//��ʼ����i�����һ�����ڵ㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, len - 1);
		szk_print_arr("�м�0:", arr, len);
	}
	//�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
	for (int i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
		szk_print_arr("�м�1:", arr, len);
	}
}



int main() {
	int arr[] = { 3, 15, 233, 20, 8, 36, 11, 45, 888, 56, 2, 74, 9, 64, 7, 80, 1, 98, 1239, 117, 683, 191, 882, 5, 109, 777, 14, 0, 22, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	szk_heap_sort(arr, len);
    szk_print_arr("����:", arr, len);
	return 0;
}
