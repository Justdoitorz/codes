#include <iostream>
#include <string>

//using namespace std;
using std::cout;
using std::endl;
using std::string;

namespace myspace {
    namespace son {
    }
}

namespace myspace {
    using u08_t = unsigned char;
    using s08_t = signed char;
    using u16_t = unsigned short;
    using s16_t = signed short;
    using u32_t = unsigned long;
    using s32_t = signed long;
    using u64_t = unsigned long long;
    using s64_t = signed long long;
}

namespace myspace {
    uint32_t add(u32_t a, u32_t b)
    {
        return a+b;
    }
}



namespace {
int a; // instead of static int a;
}

namespace myspace {
    void hello()
    {
        cout << "Hello!" << endl;
    }
}

namespace myspace {
    namespace son {
        void sonOfBitch()
        {
            cout << "You son of a bitch!" << endl;
        }
    }
}

void foo()
{
    namespace wtf = myspace;
    wtf::hello();
}

void swap(int &a, int &b)
{
    if (a == b) return;

    a ^= b;
    b ^= a;
    a ^= b;
}

int main ()
{
    uint32_t sum = myspace::add(5555, 7777);
    cout << sum << endl;

    foo();

    namespace son = myspace::son;
    son::sonOfBitch();
    namespace wtf = myspace;
    using namespace wtf;
    hello();

    string s = "Cao";
    string r = std::move(s);
    operator<<(cout, s);

    int a = 2, b = 3;

    swap(a, b);
    cout << a << ", " << b << endl;

    swap(a, a);
    cout << a << endl;

    return 0;
}
