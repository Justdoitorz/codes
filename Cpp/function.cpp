#include <iostream>
#include <functional>
#include <vector>

using std::function;

int add(int a, int b)
{
    return a + b;
}

class multiplies {
public:
    virtual ~multiplies() = default;
    int operator()(int a, int b) const
    {
        return a * b;
    }
    int result;
};

class mul: public multiplies {
public:

};

auto divides(int a, int b)->decltype(a/b)
{
    return a / b;
}

int main()
{
    function<int(int, int)> func = add;
    function<int(int, int)> lambda = [](int a, int b){ return a - b; };
    function<int(int, int)> obj = multiplies();
    function<int(int, int)> div = divides;
    std::cout << func(20, 10) << std::endl;
    std::cout << lambda(20, 10) << std::endl;
    std::cout << obj(20, 10) << std::endl;
    std::cout << div(20, 10) << std::endl;
    int i = 666;

    decltype((i)) b = i;

    int&& r = 123;
    const int& l = 123;
    decltype(l) c = 123;
    //decltype()


    multiplies *mp = new mul();
    mul m;
    multiplies &lm = m;

    mul *lmul = dynamic_cast<mul*>(mp);

    return 0;
}
