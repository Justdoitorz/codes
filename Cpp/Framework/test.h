#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
class A {
public:
    A()
    {
        std::cout << "A()" << std::endl;
        printf("%p\n", &bar);
        std::cout << &bar << std::endl;
    }
    inline A(int);
    void foo() 
    {
        std::cout << "foo()" << std::endl;
    }
    void bar() 
    {
        std::cout << "bar()" << std::endl;
    }

    //inline void foo(int);
};
A::A(int a) { std::cout << "A::A(int a)" << std::endl; }
//void A::foo(int a) { std::cout << "void A::foo(int a)" << std::endl; }
#endif
