#include <iostream>
#include <random>

using namespace std;


int main()
{
    default_random_engine e(13213);
    cout << e.min() << ", " << e.max() << endl;
    default_random_engine::result_type a;
    e.seed(0);
    for (size_t i = 0; i < 10; ++i) {
        cout << e() << endl;
    }

    uniform_int_distribution<unsigned> u(0, 9);
    for (size_t i = 0; i < 10; ++i) {
        cout << u(e) << endl;
    }
    return 0;
}
