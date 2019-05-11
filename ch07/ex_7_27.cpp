#include <iostream>

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h*w,' ') {}
    Screen(pos h, pos w, char c): height(h), width(w), contents(h *w, c) {}
    inline char get() const
        { return contents[cursor];}
    char get(pos h, pos w) const;
    Screen& move(pos r, pos c);
    inline Screen& set(const char &c)
        { contents[cursor] = c;return *this;}
    inline Screen& display(std::ostream &os)
        { doDisplay(os); return *this;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    inline void doDisplay(std::ostream &os) const
        { os << contents[cursor];}
};
inline
char Screen::get(pos h, pos w) const {
    pos row = h*width;
    return contents[row+w];
}
inline
Screen& Screen::move(pos r, pos c) {
    pos row = r*width;
    cursor = row+c;
    return *this;
}

int main() {
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << '\n';
    myScreen.display(std::cout);
    std::cout << '\n';
    return 0;
}
