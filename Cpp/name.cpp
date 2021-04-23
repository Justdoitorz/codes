#include <iostream>
using namespace std;

namespace A {
    enum week {
        SUN,
        MON,
    };
}


int main()
{
    cout << A::SUN << endl;
    return 0;
}
