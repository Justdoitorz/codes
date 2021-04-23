#include <iostream>
#include <vector>

using namespace std;

class Screen {
    friend class Window_mgr;
    friend std::ostream &storeOn(std::ostream &, Screen &);
public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c)
        : height(ht)
        , width(wd)
        , contents(ht*wd, c)
    {

    }

    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);

    void some_member() const;

    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable size_t access_ctr;
};

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r*width;
    cursor = row+c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r*width;
    return contents[row+c];
}

void Screen::some_member() const
{
    ++access_ctr;
}

inline Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    pos row = r*width;
    contents[row+c] = ch;
    return *this;
}



class Window_mgr {
public:
    using ScreenIndex = std::string::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height*s.width, ' ');
}

int main()
{
    Screen::pos ht = 24, wd = 80;
    Screen myscreen(ht, wd, 'o');
    Screen screen2 = myscreen;
    //char ch = myscreen.get();
    //cout << ch << endl;
    //cout << myscreen.get(100, 200) << endl;
    myscreen.display(cout).set(0, 0, 'A').display(cout);

    Screen myscreen_2(5, 5, 'X');
    myscreen_2.move(4, 0).set('#').display(cout);
    cout << "\n";
    myscreen_2.display(cout);
    cout << "\n";

    screen2.display(cout);
    return 0;
}
