#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

class Base {
public:
    Base()
    {
        cout << "Base" << endl;
    }
    virtual
    ~Base()
    {
        cout << "~Base" << endl;
    }
};

class Derive : public Base {
public:
    Derive()
    {
        cout << "Derive" << endl;
    }
    ~Derive()
    {
        cout << "~Derive" << endl;
    }
};

int func(const char *str)
{
    cout << str << "  " <<  endl;
}

int func(const string &str)
{
    cout << str <<  "" <<  endl;
}

int main()
{
    Base *b = new Base();
    Base *d = new Derive();
    delete b;
    delete d;
    string str = string("hello ");

    func(str.c_str());

    char buf[32] = "int:";
    int i = 1024;
    //strcat();
    sprintf(buf + strlen(buf), "%d", i);
    cout << buf << endl;
    return 0;
}
