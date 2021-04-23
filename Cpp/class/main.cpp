#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

class Test {
public:
    explicit Test(int a = 0) : _a(a)
    {
        printf("Test(), %p\n", this);
    }

    Test(const Test &t) : _a(t._a)
    {
        printf("Test(const Test &t), %p \n", this);
    } 
    Test(Test &&t) noexcept 
    : _a(t._a)  
    {
        printf("Test(Test &&t), %p\n", this);
        t._a = -1;
    }

    Test &operator=(const Test &t)
    {
        printf("Test &operator=(const Test &t)\n");
        _a = t._a;
        return *this;
    }

    Test &operator=(Test &&t) noexcept
    {
        printf("Test &operator=(Test &&t) \n");
        _a = t._a;
        t._a = -1;
        return *this;
    }
    ~Test()
    {
        printf("~Test:%p .. _a : %d\n", this, _a);
    }

    void show() const 
    {
        printf("_a: %d\n", _a);
    }

    void ref_qual() &
    {
        cout << "&" << endl;
    }

    void ref_qual() const &
    {
        cout << "const &" << endl;
    }

    void ref_qual() &&
    {
        cout << "&&" << endl;
    }

    void ref_qual() const &&
    {
        cout << "&&" << endl;
    }

    void foo()
    {
        cout << "foo" << endl;
    }
    const Test &&make()
    {
        return std::move(*this);
    }
    int _a;
};

Test foo()
{
    Test t(4), o(6);
    int a = 2;
    printf("foo end., &t = %p, &o = %p,  &a = %p\n", &t, &o, &a);
    return o;
}

Test &&bar()
{
    static Test t(5);
    printf("&t = %p\n", &t);
    return  std::move(t);
}

template<typename T>
class vr{
public:
    vr ()
    {
        std::cout << "vr" << std::endl;
    }
    
    template<typename R> 
    struct WTF {
        typedef int Ty;
    };
};

template<typename V, typename R>
class WV {
public:
    typedef typename V::template WTF<R>::Ty Ty;
};


template<typename KT, typename VT>
struct kvpair{
    typedef KT TKEY;
    typedef VT TVALUE;
};

template<typename K, typename V, 
    template<typename, typename> typename kv
>
struct keyvalue {
    typedef typename kv<K, V>::TKEY Tk;
    typedef typename kv<K, V>::TVALUE Tv;
    Tk _key;
    Tv _value;
};

template<typename T>
void bar(T &&t)
{
     Test mc(std::forward<T>(t));
}

class Base {
public:
    Base(int a = 0) : p(new int(a))
    {
        std::cout << "Base()" << std::endl;
    }
    Base(const Base &b) : p(new int)
    {
        *p = *(b.p);
    }
    Base &operator=(const Base &b) 
    {
        *p = *(b.p);
        return *this;
    }
    ~Base() 
    {
        if (p != nullptr) {
            delete p;
        }
    }

    int getValue()
    {
        return *p;
    }

    void setValue(int val)
    {
        *p = val;
    }
    
private:
    int *p;
};

 enum class ec {
    zero, one, two, three,
};
int toInt(ec e)
{
    return static_cast<int>(e);
}
int main()
{
    /*Base b;
    std::cout << b.getValue() << std::endl;
    b.setValue(100);
    std::cout << b.getValue() << std::endl;
    Base c(b);
    c.setValue(1024);
    std::cout << b.getValue() << std::endl;

    int *p = new int(9);

    delete p;delete p;delete p;delete p;

    keyvalue<int, double, kvpair>::Tk i = 8;
    //WV< vr<int> , double>::Ty d = 2.2;
    std::vector<Test> vt;
    //std::cout << vt.capacity() << std::endl;
    //Test d;
    Test dc(1);
    //bar(std::move(dc));
    Test cc(2);
    const Test oc = cc;
    Test coc = oc;
    std::cout << dc._a << std::endl;
    vt.push_back(std::move(dc));
    vt.push_back(cc);
    vt.push_back(cc);
    //vt.push_back(cc);

    for (auto iter = vt.begin(); iter != vt.end(); iter++) {
        std::cout << iter->_a << std::endl;
    }
   */
/*
    Test dc;
    dc.show();
    Test cc(dc);
    cc.show();

    Test dc2 = Test(3);
    Test mc(std::move(Test(2)));

    mc.show();

    Test &&r = Test(3);
    r.show();

    Test &&fr = foo();
    fr.show();
    foo();
    std::cout << "const &lr" << std::endl;
    const Test &lr = foo();
    std::cout << "const &lr end" << std::endl;

    mc = foo();
    mc.show();
    cc = mc;
    cc.show();
    
    
    const Test ccc = cc;
    const Test &&mr = std::move(ccc);
    printf("...\n");
    Test &&t = bar();
    Test &&to = bar();
    printf("&to = %p, &t = %p\n", &to, &t);
    printf("main end\n");
    std::cout << std::hex << 15 << std::endl;
    int &&i = 2;
    i = 3;
    std::cout << i << std::endl;
   */
    //Test a(1);
    Test a;
    a.ref_qual();
    a.foo();
    const Test b;
    b.ref_qual();
    //b.foo();
    Test().ref_qual();
    Test().foo();
   
    a.make().ref_qual();

    int ii = 0, *p = &ii, &r = ii;
    decltype((ii)) ri = (ii);
    decltype(*p) pr = *p;
    decltype(r = 3) rr = r;

    vector<Test> vt;
    vt.push_back(Test(1));

    for (auto &t : vt) {
        cout << t._a << endl;
    }

    for (auto iter = vt.begin(); iter != vt.end(); iter++) {
        cout << iter->_a << endl;
    }
    return 0;
}