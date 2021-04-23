#include <iostream>

using namespace std;

class Person{
public:
    char name[16];
    int age;

};

void test(void)
{
    Person p = {"Xiaohuozi", 24};
    cout << p.name << p.age << endl;
}

int main()
{
    test();
    return 0;
}
