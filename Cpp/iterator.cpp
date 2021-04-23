#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <list>

using namespace std;

int main()
{
    string str = "Hello";
    cout << str << endl;
    const  string s("I love you");
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter ;
        //*iter = toupper(*iter);
    }

    vector<int> v{0, 1, 2, 3, 4, 5};
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter ;
    }
    cout << endl;

    return 0;
}
