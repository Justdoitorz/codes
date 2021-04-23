#include <iostream>

using namespace std;

class Real {
public:
    Real(int vr = 1) : r(vr) { cout << "Real()" << endl; printf("*(this:%p) is %x\n", this, *(int *)this); }
    void func()
    {
        cout << "Real.func()" << endl;
    }
    void vfunc()
    {
        cout << "Real.vfunc()" << endl;
    }
    int r;
};

class Derived : public Real {
public:
    int d;
    Derived(int vr = 1, int vd = 2) : Real(vr), d(vd) { cout << "Derived()" << endl; printf("*(this:%p) is %x\n", this, *(int *)this);}
    void func()
    {
        cout << "Derived.func()" << endl;
    }
    virtual void vfunc()
    {
        cout << "Derived.vfunc()" << endl;
    }
    virtual void vfunc(int)
    {
        cout << "Derived.vfunc(int)" << endl;
    }
};

class Third : public Derived {
public:
    int t;
    Third(int vr = 1, int vd = 2, int vt = 3) : Derived(vr, vd), t(vt) { cout << "Third()" << endl; printf("*(this:%p) is %x\n", this, *(int *)this);}
    void func()
    {
        cout << "Third.func()" << endl;
    }
    virtual void vfunc()
    {
        cout << "Third.vfunc()" << endl;
    }
    virtual void vfunc(int)
    {
        cout << "Third.vfunc(int)" << endl;
    }
};


int main()
{
    //Real r;
    //Derived d;
    Third t;
    Real &rr = t;
    Derived &rd = t;
    //Third &rt = t;
/*
    rr.func();
    rr.vfunc();

    rd.func();
    rd.vfunc();

    rt.func();
    rt.vfunc();

    cout << sizeof(r) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(t) << endl;

    printf("Real.func = %p\n", Real::func);
    printf("Real.vfunc = %p\n", Real::vfunc);
    printf("Derived.func = %p\n", Derived::func);
    printf("Derived.vfunc = %p\n", Derived::vfunc);
    printf("Third.func = %p\n", Third::func);
    printf("Third.vfunc = %p\n", Third::vfunc);

    int *p = (int *)&d;
    printf("*p = %x\n", p[0]);
    printf("*p = %x\n", p[1]);
    printf("*p = %x\n", p[2]);
    */
    //printf("*p = %x\n", p[3]);
    printf("rd.r = %d\n", rd.r);

    rd.vfunc();
    rd.vfunc(0);
    //cout << rd.r << endl;
    //cout << rt.r << endl;
    //cout << sizeof(void *) << endl;
    return 0;
}
