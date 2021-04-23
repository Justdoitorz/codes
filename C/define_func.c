#include <stdio.h>

int main()
{
    __func__;
    printf("%s\n", __func__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FILE__);
    printf("%s\n", __FUNCTION__);
    printf("%d\n", __STDC__);
    return 0;
}
