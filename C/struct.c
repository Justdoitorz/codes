#include <stdio.h>
#include "pr_type.h"


typedef struct {
    union {
        uint64_t dst64;
        uint8_t dataArr[8];
    };

    uint32_t id;
	uint8_t dlc;
}can_base_t;

int main()
{
    int b[3] = {1};
    can_base_t a;
    char  c[23] = {0};
    printf("c:%p\n", c);
    printf("b:%p\n", b);
    printf("a:%p\n", &a);
    scanf("%s", c);
    printf("%d\n", sizeof(can_base_t));

    return 0;
}
