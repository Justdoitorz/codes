#include <iostream>
#include <initializer_list>
#include <typeinfo>
#include <cassert>

using namespace std;

struct Sales_data {
    friend istream& read(istream &is, Sales_data &item);
    friend ostream& print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const string &s) : BookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) :
                BookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is);

    string          ibsn() const {return this->BookNo;}
    Sales_data&     combine(const Sales_data&);
    double          avg_price() const;

private:
    string          BookNo;
    unsigned        units_sold = 0;
    double          revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    if (units_sold) {
        return revenue/units_sold;
    }
    else {
        return 0;
    }
}

istream& read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.BookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
    os << item.ibsn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
//lhs : left hand side
//rhs : right hand side
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    char str_[] = "\x902";
    Sales_data a;
    int num;
    read(cin, a) >> num;
    print(cout, a) << endl << num << endl;

    cout << a.ibsn() << endl;
    cout << a.avg_price() << endl;
    return 0;
}
