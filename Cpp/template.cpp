#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> vc;
    vector<char>::difference_type s;
    vc.push_back('a');
    const vector<char> &request = vc;
    //request.pop_back();
    //int a[10] = malloc(10*sizeof(int));
    bool a;
    vector<int> vi;
    vector<int, allocator<int>> vi2;
    return 0;
}
