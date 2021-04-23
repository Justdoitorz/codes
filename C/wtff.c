#include <stdio.h>

int func(int *argv)
{
    printf("%d\n", ((char *)argv[6])[-2]);
    return ((char *)argv[6])[-2];
}

int main()
{
    char str[7][6] = {
        "Hello",
        "World",
        "Kitty",
        "James",
        "CCCCC",
        "BBBBB",
        "AAAAA",
    };

    int arr[7] = {str[0], str[1], str[2], str[3], str[4], str[5], str[6]};
    func(arr);
}
