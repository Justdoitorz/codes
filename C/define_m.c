#include <stdio.h>

#define ALIGN_DOWN(x, a) ((x) & -(a))
#define ALIGN_UP(x, a) (-(-(x) & -(a)))

#define ALIGN_DOWN_M(x, a) ((x) & ~((a)-1))
#define ALIGN_UP_M(x, a) (((x)+(a)-1) & ~((a)-1))

#define ALIGN    (1<<9)

void func_signed_char_test(void)
{
    int i = 0;
    char c = 0;
    printf("%s\n", __func__);
    while (i != 256) {


        if (ALIGN_DOWN(c, ALIGN) != ALIGN_DOWN_M(c, ALIGN)) {
            printf("DOWN ..unequal...\n");
        }

        if (ALIGN_UP(c, ALIGN) != ALIGN_UP_M(c, ALIGN)) {
            printf("UP ..unequal...\n");
        }

        i++;
        c++;
    }

}

void func_unsigned_char_test(void)
{
    int i = 0;
    unsigned char c = 0;
    printf("%s\n", __func__);
    while (i != 256) {


        if (ALIGN_DOWN(c, ALIGN) != ALIGN_DOWN_M(c, ALIGN)) {
            printf("DOWN ..unequal...\n");
        }

        if (ALIGN_UP(c, ALIGN) != ALIGN_UP_M(c, ALIGN)) {
            printf("UP ..unequal...\n");
        }

        i++;
        c++;
    }

}
int main()
{
    unsigned int t = -18;

    printf("ALIGN_UP(t, 16) = %d\n", ALIGN_UP(t, 16));
    printf("ALIGN_UP(t, 16) = %d\n", ALIGN_UP_M(t, 16));

    func_signed_char_test();
    func_unsigned_char_test();

    return 0;
}
