#include <stdio.h>

void unsigned_move_test(void)
{
    unsigned int i = 0xFFFFFFFF;
    printf("%X\n", i << 2); //0xFFFF FFFC
    printf("%X\n", i >> 2); //0x3FFF FFFF
}

void signed_move_test(void)
{
    signed int i = 0xFFFFFFFF;
    printf("%X\n", i << 2); //0xFFFF FFFC
    printf("%X\n", i >> 2); //0xFFFF FFFF
}

int main()
{
    unsigned_move_test();
    signed_move_test();

    int b = 0x10;
    b = b << -8;
    printf("%d", b);
    return 0;
}
