#include <iostream>
#include <cmath>

using namespace std;

int main (void)
{
int a, b, c, n;
for (a = 0; a <=7; ++a)
{
for (b = 0; b <=7; ++b)
{
for (c = 0; c <=7; ++c)
{
if ((24 * a + 3 * b - 40 * c) == 0 && (a != 0 || b != 0 || c != 0))
{
n = c * pow(7,0) + b * pow(7,1) + a * pow(7,2);
cout << n;
cout << a << b << c;
cout << c << b << a << endl;
// cout << (c * pow(7,0) + b * pow(7,1) + a * pow(7,2)) << a << b << c << c << b << a << endl;
// cout << a << b << c;
// cout << c << b << a;
}
}
}
}
return 0;
}
