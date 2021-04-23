#include <stdio.h>

void func(void)
{
    int arr[128];
    printf("func:arr[127]'p = %p\n", &arr[127]);
}

int main()
{
    int len;
    printf("len'p = %p\n", &len);
    scanf("%d", &len);

    int arr[len];



    int last;
    printf("%p\n", &last);
    scanf("%d", &last);
    func();
    printf("arr[%d]'p = %p\n", last, &arr[last]);

    return 0;
}
