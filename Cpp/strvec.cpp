#include <iostream>
#include <memory>
#include "strvec.h"

using namespace std;

std::allocator<std::string> StrVec::alloc;


void StrVec::push_back(const string &s)
{
    chk_n_alloc();

    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);

    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::~StrVec()
{
    //cout << "StrVec::~StrVec()" << endl;
    free();
}

StrVec::StrVec(const StrVec &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = uninitialized_copy(make_move_iterator(begin()),
                                   make_move_iterator(end()),
                                   newdata);
    /*
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size() ; ++i)
        alloc.construct(dest++, std::move(*elem++));
    */

    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;



}

int main()
{
    StrVec sv;
    sv.push_back("wtf");
    sv.push_back("fuck");
    sv.push_back("you");
    cout << sv.size() << endl;
    cout << sv.capacity() << endl;

    StrVec svo(sv);

    cout << svo.size() << endl;
    cout << svo.capacity() << endl;

    sv = svo;
    cout << sv.size() << endl;
    cout << sv.capacity() << endl;
    return 0;
}
