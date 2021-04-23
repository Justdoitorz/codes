#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Screen {
public:
    typedef std::string::size_type pos;
    Screen(const std::string &s = string()): contents(s), cursor(0), height(0), width(0) { }
    char get_cursor() const { return contents[cursor]; }
    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const { return contents[ht+wd]; }

    static const std::string Screen::*data()
    {
        return &Screen::contents;
    }
private:
    std::string contents;
    pos cursor;
    pos height, width;
};


int main()
{
    const string Screen::*pdata = Screen::data();
    Screen myScreen("oh my god!");
    auto s = myScreen.*pdata;

    auto pmf = &Screen::get_cursor;
    char (Screen::*pmf1)() const = &Screen::get;
    char (Screen::*pmf2)(Screen::pos, Screen::pos) const = &Screen::get;

    cout << (myScreen.*pmf1)() << endl;
    cout << (myScreen.*pmf2)(1, 2) << endl;

    cout.setf()
    return 0;
}
