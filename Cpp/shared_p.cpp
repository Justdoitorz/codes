#include <iostream>
#include <memory>

using namespace std;

int main()
{
    string *p;
    {shared_ptr<string> p1 = make_shared<string>();
    shared_ptr<string> p2 = make_shared<string>("fuck you");
    if (p1 && p1->empty()) {
        *p1 = "son of a bitch";
    }
    cout << *p1 << endl;
    p = p1.get();
    p1.swap(p2);
    cout << *p1 << endl;
    cout << p1.unique() << endl;
    cout << p1.use_count() << endl;
    }
    cout << *p << endl;

    return 0;
}
