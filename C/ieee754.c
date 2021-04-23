#include <stdio.h>

struct float_bits {
    unsigned long M : 23;
    unsigned long E : 8;
    unsigned long S : 1;
};

struct double_bits {
    unsigned long long M : 52;
    unsigned long long E : 11;
    unsigned long long S : 1;
};

union uf{
    unsigned long l;
    float f;
    struct float_bits fb;
};

union ud{
    unsigned long long ll;
    double d;
    struct double_bits fd;
};

int main()
{
    union uf f;
    f.f = 0.5f;
    printf("0x%08X\n", f.l);
    printf("S: %ld, E: %ld, M: 0x%06X\n", f.fb.S, f.fb.E, f.fb.M);
    return 0;
}
