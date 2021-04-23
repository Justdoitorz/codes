#include <stdio.h>

int pow2n(int n)
{
    return 1 << n;
}

int getOffset(int n)
{
    int pos = 0;

    while ((n&1) == 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

void func(int n)
{
    int first = 0, i, offset;

    for (i = 0; i < pow2n(n); i++) {
        printf("%8d", first);
        offset = getOffset(i+1);
        first ^= (1 << offset);
    }
    printf("\n");
}

int getEncryption(int n)
{
    int first = 0, offset;
    if (n) {
        offset = getOffset(n+1);
        first ^= (1 << offset);
    }
}

int main()
{
    //func(0);
    func(1);
    func(2);
    func(3);
    func(4);
    func(5);
    func(6);

    return 0;
}
