#include <iostream>
#include <string>

using namespace std;

string foo(const char *str = "Hello world")
{
    return string(str);
}

int main()
{
    string str("Hello");
    const char *p = foo().c_str();
    cout << std::hex << (void *)p << endl;
    cout << std::hex << &str << endl;
    cout << std::hex << (void *)str.c_str() << endl;
    return 0;
}
