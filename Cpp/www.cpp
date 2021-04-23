#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
unsigned int a(const char *s,int n);
int main()
{
        a("Hello, what is your name?????", 500);
        return 0;
}
unsigned int a(const char *s,int n)
{
        while(*s)
        {
                cout<<*s++;
                Sleep(n);
        }
    return 0;
}
