#include <iostream>
#include <typeinfo>
//#include <winsock2.h>
#include <cstring>
//#include<WS2tcpip.h>
using std::cout;
using std::endl;

class Base {
public:
    Base()
    {
        cout << "Base()" << endl;
    }
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived: public Base {
public:
    Derived()
    {
        cout << "Derived()" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

class A {
public:
    virtual ~A() {}
};

class B: virtual public A
{

};

class C: virtual public A
{

};

class D: public B, public C {

};

int main(void)
{
    Base *b = new Base();
    cout << typeid(*b).name() << endl;

    Derived *d = new Derived();
    cout << typeid(*d).name() << endl;

    Base *bd = new Derived();
    cout << typeid(*bd).name() << endl;

    Base& blr = *bd;
    if (Derived *db = dynamic_cast<Derived*>(bd)) {
        cout << "wtf" << endl;
    }

    Derived& dlr = dynamic_cast<Derived&>(*bd);
    cout << "dynamic_cast<Derived&>" << endl;

    Derived&& drr = dynamic_cast<Derived&&>(Derived());
    cout << "dynamic_cast<Derived&&>" << endl;

    C *pa = new C();
    if (B *pb = dynamic_cast<B*>(pa))
        cout << "success" << endl;

    return 0;
}
