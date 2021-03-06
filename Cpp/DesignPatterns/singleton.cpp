#include <iostream>
#include <cstdio>

using namespace std;


class Number {
public:
    static Number *instance();
    static void setType(string t)
    {
        type = t;
        delete inst;
        inst = nullptr;
    }
    virtual void setValue(int in)
    {
        value = in;
    }
    virtual int getValue()
    {
        return value;
    }
protected:
    int value;
    Number()
    {
        cout << "Number :ctor: ";
    }
private:
    static string type;
    static Number *inst;
};

string Number::type = "decimal";
Number *Number::inst = nullptr;

class Octal : public Number
{
public:
    friend class Number;
    void setValue(int in)
    {
        char buf[10];
        sprintf(buf, "%o", in);
        sscanf(buf, "%d", &value);
    }
protected:
    Octal() {}
};

Number *Number::instance()
{
    if (!inst) {
        if (type == "octal") {
            inst = new Octal();
        } else {
            inst = new Number();
        }
    }
    return inst;
}


namespace DP {
    namespace Creational {

        void singleton()
        {
            Number::instance()->setValue(42);
            cout << "value is " << Number::instance()->getValue() << endl;
            Number::setType("octal");
            Number::instance()->setValue(64);
            cout << "value is " << Number::instance()->getValue() << endl;

            Number::instance()->setValue(8);
            cout << "value is " << Number::instance()->getValue() << endl;
        }
     
    }
}