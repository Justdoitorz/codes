#include <iostream>
#include "quote.h"

using namespace std;

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return Quote::net_price(cnt);
}

class Base {
public:
    int pub_mem;
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
   // char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    int f2() const { return pub_mem; }
};

int main()
{
    Quote q;
    //Disc_quote d;
    Bulk_quote b("Jinpingmei", 10.8, 1, 0.1);

    cout << b.net_price(2) << endl;
    return 0;
}
