#include <stdio.h>
#include <stdint.h>

char HexToAscii(uint8_t val)
{
    return (val + '0') + (val/10)*('A' - '0' - 10);
}

char *HexToString(uint8_t byte)
{
    static char buf[4];
    buf[0] = 'x';
    buf[1] = HexToAscii(byte >> 4);
    buf[2] = HexToAscii(byte & 0x0F);
    buf[3] = '\0';
    return buf;
}

int main()
{
    printf("%s\n", HexToString(0xb8));
    return 0;
}
