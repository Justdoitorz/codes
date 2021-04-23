#include <iostream>
#include <string.h>

using namespace std;

class Stud {
public:
    Stud(int _no, const char *_name, int _deg)
    : no(_no), deg(_deg)
    {
        strcpy(this->name, _name);
        num++;
        sum += deg;
    }

    void disp(void) {
        cout << no << endl << name << endl << deg << endl;
    }

    static void avg(void) {
        if (num) {
            cout << (double)sum/num << endl;
        } else {
            cout << "0.0" << endl;
        }
    }
private:
    static int sum;
    static int num;

    int no;
    char name[10];
    int deg;
};

int Stud::sum = 0;
int Stud::num = 0;

int main()
{
    Stud *s1 = new Stud(1, "Joe", 100);
    Stud *s2 = new Stud(2, "John", 60);
    Stud *s3 = new Stud(3, "Mark", 1);
    s1->disp();
    s2->disp();
    s3->disp();
    Stud::avg();
    return 0;
}
