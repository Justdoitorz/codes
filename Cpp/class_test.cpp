#include <iostream>

using namespace std;

class A {
public:
    A(int v = 1024)
    : val(v)
    {

    }
    int getVal(void)
    {
        return val;
    }

    int getValEx(void)
    {
        return val*3/2;
    }

    void func_testA(void)
    {
        cout << "Class A: func_test" << endl;
    }

    void func_ex(void)
    {
        func_testA();
    }

private:
    int val;
};

class B {
public:
    B(int v = 1023)
    : val(v)
    {

    }

    int getVal(void)
    {
        return val;
    }

    void func_testB(void)
    {
        cout << "Class B: func_test" << endl;
    }

private:
    int val;
};

class C : public  A, public B {
public:
    void func(void)
    {
        cout << A::getVal() << endl;
    }

    void func_testC (void)
    {
        cout << "Class C : func_test" << endl;
    }
};

class D : public  C {
    void func_test (void)
    {
        cout << "Class D : func_test" << endl;
    }
};

int main()
{
    C pp;
    cout << &pp << endl;
    B *b = new C();
    A *a = (C *)b;
    C *c = new D();
   // C *t = (C *)new A();
   // cout << c->getVall() << endl;
    cout << b->getVal() << endl;
    cout << a->getVal() << endl;
    cout << a->getValEx() << endl;
    //cout << t->getVal() << endl;
    a->func_testA();
    c->func_testC();
    return 0;
}
