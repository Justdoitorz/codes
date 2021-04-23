#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;


int main()
{
    vector<string *> v;
    string a("1234");string b("222");
    v.push_back(&a);
    const vector<string *> &l = v;
    vector<string *>::const_iterator i = l.begin();
    *(*i) = "222";
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << (*iter)->c_str() << endl;
    }
    return 0;
}

