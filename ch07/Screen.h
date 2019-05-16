#include <iostream>

#ifndef SCREEN_H
#define SCREEN_H


class Screen {
    friend class Window_mgr;
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, pos c):
        height(ht), width(wd), contents(wd*ht, c) {}
    inline char get() const {return contents[cursor];}
    char get(pos r, pos c) const;
    Screen& move(pos r, pos c);
    Screen& set(pos r, pos c, char ch);
    Screen& set(char ch);
    inline Screen& display(std::ostream &os)
        {do_display(os); return *this;}
private:
    void do_display(std::ostream &os) {os << contents;}
    std::string contents;
    pos cursor = 0;
    pos height = 0, width = 0;
};

#endif
