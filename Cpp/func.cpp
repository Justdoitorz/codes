#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <string>

using namespace std;


int main()
{
 int num;
 cin >> num;
clock_t start, finish;
//¶ÔSTLµÄ²âÊÔ
start = clock();
map < int, vector<string> >  stl;
string temp_stl = "er";
for (int i = 0; i < num ; i++)
{
for (int j = 0; j < num ; j++)
{
stl[i].push_back(temp_stl);
}
stl[i].shrink_to_fit();
}
for (int i = 0; i < num; i++)
{
for (int j = 0; j < num; j++)
{
    stl[i][j];
    //cout << stl[i][j] << endl;
}
}
finish = clock();
double duration = (double)(finish - start) * 1000 / CLOCKS_PER_SEC;
cout << "STL:" << duration << "ms" << endl;
    return 0;
}
