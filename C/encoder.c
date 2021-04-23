#include <stdio.h>

typedef unsigned char uint8_t;

uint8_t encoder(uint8_t n)
{
    return n^(n>>1);
}

uint8_t mask(uint8_t n)
{
    n >>= 1;
    for (uint8_t i = 7; i > 0; i--) {
        n ^= (n&(1<<i))>>1;
    }
    return n;
}

uint8_t decoder(uint8_t n)
{
    return n^mask(n);
}

uint8_t decoder_ex(uint8_t n)
{
    uint8_t mask = n;
    while (mask >>= 1) {
        n ^= mask;
    }
    return n;
}

void func(uint8_t n)
{
    for (int i = 0; i <= n; i++) {
        //printf("enc(%d): %d\n", i, encoder(i));
        printf("dec(%d): %d\n", encoder(i), decoder_ex(encoder(i)));
    }
}

int main()
{
    func(15);
    return 0;
}
