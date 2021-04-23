#include <iostream>
#include <typeinfo>
#include <vector>

struct Foo { virtual ~Foo() {} };
struct Bar: Foo { virtual ~Bar() {} };
struct Baz {
    void operator++()
    {
        std::cout << "++b" << std::endl;
    }
    void operator++(int)
    {
        std::cout << "b++" << std::endl;
    }
    int operator[](int i)
    {
        return i;
    }
};

int main()
{
    Foo b;
    Foo& r = b;
    try {
        Bar& f = dynamic_cast<Bar&>(r);
    } catch(const std::bad_cast& e) {
        std::cout << e.what() << '\n';
    }
    Bar ba;
    Foo *p = &ba;
    Baz *bz = nullptr;
    Baz bbz;
    try {
        //typeid(*bz) bz2;
        std::cout << typeid(*bz).name() << std::endl;
    } catch(const std::bad_typeid& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << bbz.operator[](29)<< std::endl;
    bbz++;
    ++bbz;
    bbz.operator++();
    bbz.operator++(0);
    std::vector<int> vi;
}
