#include <iostream>

using std::cout;
using std::endl;

enum Tokens {INLINE = 128, VIRTUAL = 129,};

void ff(Tokens t)
{
    cout << "Tokens" << endl;
}

void ff(int i)
{
    cout << "int i" << endl;
}

void newf(unsigned char uc)
{
    cout << "uc" << endl;
}

void newf(int i)
{
    cout << "newf(int i)" << endl;
}

int main()
{
    enum intValues : unsigned long long;
    enum class peppers;
    enum color {red, yellow, green};
    //enum stoplight {red, yellow, green};
    enum class peppers {red, yellow, green};
    color eyes = green;
    //peppers p = green;
    color hair = color::red;
    peppers p2 = peppers::red;
    int i = color::red;
    color skin;// = 0;
    skin = color::yellow;
    //int j = peppers::red;
    enum intValues : unsigned long long {
        charTyp = 255,
        shortTyp = 65535,
        intTyp = 65535,
        longTyp = 4294967295L,
        long_longTyp = 18446744073709551615ULL
    };

    Tokens curTok = INLINE;
    ff(128);
    ff(curTok);
    ff(VIRTUAL);

    unsigned char uc = VIRTUAL;
    newf(VIRTUAL);
    newf(129);
    newf(uc);
    return 0;
}
