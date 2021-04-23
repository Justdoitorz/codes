#include <iostream>

using namespace std;

typedef enum{
    KINGDOM_ANIMAL = 0,
    KINGDOM_BOTANY,
}eKINGDOM;

class Animals {
public:
    eKINGDOM _Kingdom = KINGDOM_ANIMAL;
    int _age;

    Animals(int age = 1)
    {
        _age = age;
    }
    ~Animals()
    {
    }

    int getAge(void)
    {
        return _age;
    }
    void setAge(int age)
    {
        _age = age;
    }
};

class Chordata: public Animals {
private:
    int Phylum;
public:
    Chordata(int age = 2)
    {
        _age = age;
    }


};


int main()
{
    Animals a(2);
    Chordata b(5);
    //b.setAge(3);
    cout << a.getAge() << endl;
    cout << b.getAge() << endl;

    return 0;
}
