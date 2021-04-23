#include <iostream>
#include <sstream>
//#include <stream>
#include <iterator>
#include <array>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

#include <list>
#include <forward_list>

#include <map>
#include <set>

#include <unordered_map>
#include <unordered_set>

#include <utility>

#include <typeinfo>
#include <stdlib.h>

using namespace std;


void display_category(random_access_iterator_tag)
{
    cout << "random_access_iterator" << endl;
}
void display_category(bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator" << endl;
}
void display_category(forward_iterator_tag)
{
    cout << "forward_iterator" << endl;
}
void display_category(input_iterator_tag)
{
    cout << "input_iterator" << endl;
}

void display_category(output_iterator_tag)
{
    cout << "output_iterator" << endl;
}


template <typename I>
void display(I iter)
{
    typename iterator_traits<I>::iterator_category cagy;
    display_category(cagy);
    cout << "typeid(iter).name() = " << typeid(iter).name() << endl << endl;
}



int main()
{
    array<int, 10> ai10 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto a : ai10) {
        cout << a << endl;
    }
    display(array<int, 10>::iterator());
  

    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : vi) {
        cout << i << endl;
    }
    display(vector<int>::iterator());

    deque<int> di = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : di) {
        cout << i << endl;
    }
    display(deque<int>::iterator());
    
    //display(stack<int>::iterator());
    //display(queue<int>::iterator());

    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : li) {
        cout << i << endl;
    }
    display(list<int>::iterator());

    list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : fli) {
        cout << i << endl;
    }
    display(forward_list<int>::iterator());

    map<int, int> mii = {{0, 123}, {1, 2423}, {2, 1123}, {3, 233465}, {4, 21346},};
    for (auto kv : mii) {
        cout << kv.first << ", " << kv.second << endl;
    }
    display(map<int, int>::iterator());

    set<int> si = {1, 2, 3, 4, 5};
    for (auto s : si) {
        cout << s  << endl;
    }
    display(set<int>::iterator());

    multimap<int, int> mmii = {{0, 123}, {1, 2423}, {2, 1123}, {1, 233465}, {2, 21346},};
    for (auto kv : mmii) {
        cout << kv.first << ", " << kv.second << endl;
    }
    display(multimap<int, int>::iterator());

    multiset<int> msi = {1, 2, 3, 4, 5, 4, 3, 2, 1,};
    for (auto s : msi) {
        cout << s  << endl;
    }
    display(multiset<int>::iterator());

    unordered_map<int, int> umii = {{0, 123}, {1, 2423}, {2, 1123}, {3, 233465}, {4, 21346},};
    for (auto kv : umii) {
        cout << kv.first << ", " << kv.second << endl;
    }
    display(unordered_map<int, int>::iterator());

    unordered_set<int> usi = {1, 2, 3, 4, 5};
    for (auto s : usi) {
        cout << s  << endl;
    }
    display(unordered_set<int>::iterator());

    unordered_multimap<int, int> ummii = {{0, 123}, {1, 2423}, {2, 1123}, {1, 233465}, {2, 21346},};
    for (auto kv : ummii) {
        cout << kv.first << ", " << kv.second << endl;
    }
    display(unordered_multimap<int, int>::iterator());

    unordered_multiset<int> umsi = {1, 2, 3, 4, 5, 4, 3, 2, 1,};
    for (auto s : umsi) {
        cout << s  << endl;
    }
    display(unordered_multiset<int>::iterator());

    display(istream_iterator<int>());
    display(ostream_iterator<int>(cout, ""));

    /*int a = 0;
    int *p;
    p = &(-a);
    p = &(a + 2);
    p = &(a = 2);
    p = &(a += 2);
    p = &(a ++);
    p = &(++ a);
    p = &(!a);
    p = &(*p);*/

    char a = 178;
    cout << a << endl;

    string fstr = "1.234";
    istringstream iss(fstr);
    float f;

    iss >> f;
    cout << f << endl;
    
    return 0;
}


typedef int(*iap10)[10]  ;
//int (*func(int))[10];
auto func(int) -> iap10;s
iap10 func(int r)
//int (*func(int r))[10]
{
    static int arr[10][10];
    return &arr[r];
}