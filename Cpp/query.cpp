#include "query.h"
#include <iostream>

using namespace std;

int main()
{
    Query f = Query("hello") & Query("wind") | Query("mdzz");
    cout << f << endl;
    return 0;
}
