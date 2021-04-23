#include <iostream>
#include <tuple>

using namespace std;
using std::tuple;
using std::string;
using std::cout;
using std::endl;

int main()
{
    tuple<char, short, int, long, float, double> t('a', 1, 2, 3, 4.1, 5.2);
    auto mt = std::make_tuple('S', char(888));
    tuple<char, short> &&rr = std::make_tuple('S', (888));
    tuple<char, short> &o = rr;
    //bool e = t == rr;
    bool tt = rr == o;
    cout << get<1>(rr) << endl;
    cout << tuple_size<decltype(mt)>::value << endl;
    //tuple_element<1, decltype(mt)>::type a;
    //cout << sizeof(a) << endl;
    int &l = std::get<2>(t);
    short &&r = std::get<1>(std::make_tuple('A', short(99)));
    cout << r << endl;
    return 0;
}
