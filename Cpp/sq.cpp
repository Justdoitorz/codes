#include <iostream>

struct cc
{
    int a, b;
    void cd(int x, int y)
    {
        a = x, b = y;
    }
};

int main()
{
    struct cc a = {2, 3};;

    printf("我爱你%d, %d\n", a.a, a.b);
    std::cout << "我也不懂" << std::endl;
    return 0;
}
