#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(string nums)
{
    return nums.size() > 5;
}

int main()
{
    string line, word;
    vector<PersonInfo> People;
    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        People.push_back(info);
    }

    for (const auto &peo : People) {
        cout << peo.name;
        for (const auto &pho : peo.phones) {
            cout << " " << pho;
        }
        cout << endl;
    }

    for (const auto &entry : People) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << nums;
            }
        }

        ostream &os = cout;
        if (badNums.str().empty()) {
            os << entry.name << " "
               << formatted.str() << endl;
        } else {
            cerr << "input error: " << entry.name
                 << "invaild number(s) " << badNums.str() << endl;
        }
    }


    return 0;
}
