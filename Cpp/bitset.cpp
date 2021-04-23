#include <iostream>
#include <bitset>

using namespace std;


int main()
{
    bitset<6> b(15);
    cout << b.to_string('0', '1') << endl;
    cout << b.count() << endl;
    cout << b.size() << endl;
    b.set(5);
    cout << b.to_string('0', '1') << endl;
    b.set();
    cout << b.to_string('0', '1') << endl;

    b.reset(0);

    cout << b.to_string('a', 'b') << endl;

    cout << b << endl;

    bitset<64> c(~0LL);
    cout << b[2] << endl;
    auto ul = c.to_ulong();

    //cout << s << endl;
    return 0;
}
