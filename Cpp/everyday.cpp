#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Demo {
public:
    Demo(int m, int d) : money(m), debt(d)
    {

    }

    Demo(const Demo &) 
    {
        cout << "copy construct" << endl;
    }

    Demo operator+(const Demo &rhs)
    {
        return Demo(money + rhs.money, debt + rhs.debt);
    }



    void show(void)
    {
        std::cout << "money: " << money << std::endl;
        std::cout << "debt: " << debt << std::endl;
    }
private:
    int money;
    int debt;
};

int main()
{
    Demo you(10000, 200);
    Demo her(100000, 800);

    Demo merge(you);

    merge = you + her;
    merge.show();

    int a = 1, b;

    int *p = &(b = a = 55);

    cout << *p << endl; 
    return 0;
}
