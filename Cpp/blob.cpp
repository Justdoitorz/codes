#include "blob.h"
#include <iostream>

using namespace std;

int main()
{
    Blob<int> bi = {0, 1, 2, 3, 4, 5};

    for (size_t i = 0; !bi.empty(); ++i) {
        //cout << bi[i] << endl;
        cout << bi.back() << endl;
        bi.pop_back();
    }

    return 0;
}
