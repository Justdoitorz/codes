#include <stdio.h>


void swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void szk_swap_func(char *arr)
{
    for (int i = 0; i < 3; i++) {
        swap(arr+i*2, arr+i*2+6*2);
    }
}

void szk_print_arr(char *arr, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}
int main()
{
    char arr[32], ch;
    int idx = 0;

    //获取输入
    while ((ch = getchar()) != '\n') {
        arr[idx++] = ch;
    }

    //交换
    szk_swap_func(arr);

    //打印结果
    szk_print_arr(arr, idx);
}
