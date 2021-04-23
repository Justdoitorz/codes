#include <iostream>
#include <cstdint>

using namespace std;


int main()
{
    int count = -1;
    while (1) {
        count++;
        if (count == 0) {
            cout << "Start...." << endl;
        } else if (count < 8) {
            cout << "Idle: " << count << endl;
        } else if (count < 16) {
            cout << "Work: " << count << endl;
        } else {
            cout << "End" << endl;
            count = -1;
            break;
        }

    }
    return 0;
}
