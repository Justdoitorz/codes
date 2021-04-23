#include <iostream>

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
/*HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    delete ps;
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    return *this;
}*/

class sp {
public:
    sp(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    sp(const sp &p):
        ps(p.ps), i(p.i), use(p.use) { ++*use;}
    sp& operator=(const sp &);
    ~sp();

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

sp::~sp()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

sp & sp::operator=(const sp &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

int main()
{
    HasPtr h;
    HasPtr i(h);
    i = i;
    return 0;
}
