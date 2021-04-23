#include <iostream>


using namespace std;
class Account {
public:
    void calculate()
    {
        amount += amount*interestRate;
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

    static constexpr int period = 30;
    double daily_tbl[period];
};

void Account::rate(double newRate)
{
    interestRate = newRate;
}
double Account::initRate()
{
    return 0.0353;
}

double Account::interestRate = initRate();

int main()
{
    double r;
    r = Account::rate();
    cout << r << endl;
    return 0;
}
