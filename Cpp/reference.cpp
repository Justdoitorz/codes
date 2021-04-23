#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(const Foo&)
    {
        cout << "Foo(const Foo&)" << endl;
    }
};
/*
class HasPtr {
public:
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0;}
    HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this;}
};
*/
class Integer {
    friend ostream& operator<<(ostream &os, const Integer &i);
public:
    int val;

    Integer& operator++()
    {
        val++;
        return *this;
    }

    Integer operator++(int)
    {
        Integer ret = *this;
        val++;
        return ret;
    }
};

ostream& operator<<(ostream &os, const Integer &i)
{
    os << i.val;
}

class Double {
public:
    double val;
};

double operator+(const Integer &i, const Double &d)
{
    return i.val + d.val;
}

int main()
{
    Foo x;
    Foo y(x);
    Foo z(std::move(x));

    Integer i = {1};
    Double d = {2.1};
    cout << i + d << endl;

    string s = "hello";
    string o = "md, " + s;
    cout << o << endl;

    cout << i++ << endl;
    cout << ++i << endl;
    plus<int> intAdd;
    negate<int> intNegate;
    int sum = intAdd(10, 20);
    cout << sum << endl;
    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;
    return 0;
}
