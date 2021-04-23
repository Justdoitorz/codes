#include <iostream>
#include <cstdlib>
//#include <new>

using std::nothrow;
using std::cout;
using std::endl;

class A {
public:
    A(int i = 0): v(i)
    {
        cout << "A(int i = 0): " << i << endl;
    }
    A(int i, int j): v(i)
    {
        cout << "A(int i, int j): " << i << ", " << j << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
    int v;
};

void *operator new[](size_t s)
{
    cout << "size: " << s << endl;
    return malloc(s);
}

int main()
{
    //int x = 3, y = 4;
    //int *a = static_cast<int *>(operator new(4));
   // cout << sizeof(A) << endl;
   // A *p = static_cast<A *>(operator new[](16*sizeof(A)));
   // new(p) A[6]{{1}, {6}, {32}, {1, 2}};

   // for (int i = 0; i < 16; i++) {
   //     cout << p[i].v << endl;
    //}
    //operator new(sizeof(A), p+6);
    int a = 0;
    int *p = static_cast<int*>(operator new(4));
    new(p) int[2]{99, 122};
    cout << a << endl;
    cout << p[0] << p[1] << endl;

    int *q = new int[100];
    cout << *q << endl;

    delete(p);
    return 0;
}
