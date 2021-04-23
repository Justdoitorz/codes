#include <iostream>

using namespace std;

class Father{
public:
    char name[64];
    Father() {
        cout << "Make a father" << endl;
    }
    virtual ~Father() {
        cout << "Kill father" << endl;
    }

    virtual istream & input(istream &in) {
        in >> name;
        return in;
    }

    virtual ostream & output(ostream &out) {
        out << name << " ";
        return out;
    }
};
class Son : public Father {
public:
    char attr[64];
    Son() {
        cout << "Make a son" << endl;
    }
    ~Son () {
        cout << "Kill son" << endl;
    }

    istream & input(istream &in) {
        in >> name >> attr;
        return in;
    }

    virtual ostream & output(ostream &out) {
        out << name << " ";
        out << attr << " ";
        return out;
    }
    istream &operator>>(istream &in, Son &s) {
        in >> s.attr >> s.name;
        return in;
    }
};

class Sunzai : public Son {
public:
    char birthday[64];
    Sunzai() {
        cout << "Make a Sunzai" << endl;
    }
    ~Sunzai () {
        cout << "Kill Sunzai" << endl;
    }
    istream & input(istream &in) {
        in >> name >> attr >> birthday;
        return in;
    }

    virtual ostream & output(ostream &out) {
        out << name << " ";
        out << attr << " ";
        out << birthday << " ";
        return out;
    }
};
int main()
{
    char name[64];
    Son *s = new Son();
    //Sunzai *s = new Sunzai();
    s->input(cin) >> name;
    s->output(cout) << endl;


    cin>>*s;
    delete s;
    return 0;
}
