#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;
typedef char *pstring;

int main()
{
    static int a, b;
    char c = 128;
    cout << c << endl;
    double d;

    const int i = a;
    const int &j = i;
    const int &k = 0;

    //int &er = i;
    const char &eru = i;
    const int &l = d;

    const int *p = &i;
    p = &j;

    int * const q = &a;
    *q = 8;

    static constexpr int val = 1024;
    constexpr const int *pp = &a;

    printf("%d\n", c);

    const pstring ps = &c;
    char ccc;
    *ps = 'a';
    const char *pps = &c;
    pps = &ccc;

    return 0;
}

