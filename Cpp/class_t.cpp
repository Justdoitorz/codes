#include <iostream>
#include <string>
#include <list>
#include <deque>

using namespace std;


class NoDefault {
public:
    NoDefault(const string &){}
    NoDefault() = default;
};

struct A {
    NoDefault my_mem;
};

struct B{
    B(const string &s) : b_member(s) {}
    NoDefault b_member;
};
int main()
{
    A a;
    string s;
    B b(s);
    unsigned int u = 3;
    cout << u - 4 << endl;

    list<deque<int>> l;
    return 0;
}
