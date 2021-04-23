#include <stdio.h>
#include <windows.h>
int main()
{
    //CP1252
    SetConsoleOutputCP(1252);
    for (int i = 0; i < 256; i++) {
        printf("i: %d, %c\n", i, i);
    }

    return 0;
}
