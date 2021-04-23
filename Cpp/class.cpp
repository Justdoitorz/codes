#include <iostream>

using namespace std;

int cnt = 0;
class A {
public:
    A(int i ) ;
    A(const A &a) ;
    A(A &&a) ;
    A &operator=(const A &a) ;
    A &operator=(A &&a) ;

    ~A()
    {
        cout << v << " , ~A(): " << this << endl;
    }
    int v;
};


struct NoDtor {
    NoDtor() = default;
    ~NoDtor() = delete;
};


    A::A(int i = 0)  : v(cnt++)
    {
        cout << "A(), " << this << endl;
    }
    A::A(const A &a)  : v(cnt++)
    {
        cout << "A(const A &a), " << this << ", &a " << &a << endl;
    }
    A::A(A &&a) : v(cnt++)
    {
        cout << "A(&&a), " << this << ", &a " << &a << endl;
    }

    A &A::operator=(const A &a)
    {
        cout << "A &operator=(const A &a)" << endl;
        return *this;
    }

    A &A::operator=(A &&a)
    {
        cout << "A &operator=(A &&a)" << endl;
        return *this;
    }


void foo(A a)
{
    //int i;
    //cout << &i << endl;
    //cout << &a << endl;
}

A bar()
{
    A a;
    cout << &a << endl;
    return a;
}

A baz(A a) noexcept
{
    return a;
}
void foo()
{
    int arr[1024];
    bar();
}

int main()
{
    A a;
    A b(a);
    A r(bar());
    cout << &r << endl;
    A c(std::move(r));

    return 0;
}
