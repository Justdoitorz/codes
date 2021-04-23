#include <iostream>
#include <string>
using namespace std;


string foo(const string &s)
{
   // static string ss = "0";
   // string ret = ss;
   // ss = s;
    cout << "s: " << s << endl;
    //cout << "Debug: " << ret << endl;
    return s;
}

int main()
{
    //cout.setf(ios_base::fixed);
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0/3.0;
    double mint = 10.0/3.0;
    const float million = 1.0e6;

    cout << tub << endl;
    cout << tub * million << endl;
    cout << tub * 10 * million << endl;

    cout << mint << endl;
    cout << mint * million << endl;
    return 0;
}
