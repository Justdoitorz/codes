#include <iostream>
#include <list>
#include <deque>

using namespace std;


int main()
{
    int i;
    list<int> l;
    deque<int> d;
    list<int> result;



    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);

    d.insert(4);
    d.insert(3);
    d.insert(2);
    d.insert(1);

    for (auto liter = l.crbegin(); liter != l.crend(); liter++) {
        cout << *liter << endl;
    }




    return 0;
}
