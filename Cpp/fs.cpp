#include <iostream>
using namespace std;
class A{
    static int val;
public:

    void show_val(void)
    {
        cout << val << endl;
    }
};


int A::val = 8;


class B : public A {


public:
    int two;
};

//int B::val = 9;

int main()
{
    B para;
    para.show_val();
    cout << sizeof(para) << endl;
    return 0;
}
