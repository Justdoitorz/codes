#include <iostream>

using namespace std;

int main()
{
    int i = 123;
    int *p = &i;
    int *q = NULL;

    *p = 456;
    cout << *p << endl;

    *q = 789;
    cout << *q << endl;
    return 0;
}
