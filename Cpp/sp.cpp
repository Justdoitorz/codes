#include <iostream>
#include <memory>

using namespace std;

class Child;
class Parent;

class Parent {
private:
    Child *myChild;
public:
    Parent();
    void setChild(Child *ch) {
        this->myChild = ch;
    }

    void doSomething() {
        if (this->myChild) {
            cout << "myChild exist" << endl;
        }
    }
    ~Parent() {
        //delete myChild;
    }
};

class Child {
private:
    Parent *myParent;
public:
    void setParent(Parent *ch) {
        this->myParent = ch;
    }

    void doSomething() {
        if (this->myParent) {
            cout << "myParent exist" << endl;
            this->myParent->doSomething();
        }
    }
    ~Child() {
        //delete myParent;
    }
};

int main()
{
    Parent *p = new Parent;
    Child *c = new Child;
    p->setChild(c);
    c->setParent(p);
    c->doSomething();
    delete p;

    c->doSomething();
    p->doSomething();
    //delete(c);
    return 0;
}
