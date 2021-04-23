#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto it = unique(words.begin(), words.end());
    words.erase(it, words.end());
}

void show(vector<string> &words)
{
    cout << "----->>>>>>>>>>>>>>>>>" << endl;
    for (auto it = words.begin(); it != words.end(); it++) {
        cout << *it << endl;
    }
    cout << "<<<<<<<<<<<<<<<<<-----" << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vec;
    vec.push_back("turtle");
    vec.push_back("turtle");
    vec.push_back("the");
    vec.push_back("fox");
    vec.push_back("quick");
    vec.push_back("jumps");
    vec.push_back("over");
    vec.push_back("red");
    vec.push_back("slow");
    show(vec);
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    //stable_sort(vec.begin(), vec.end(), [](const string &a, const string &b)->bool{return a.size() < b.size();});
    show(vec);


    return 0;
}
