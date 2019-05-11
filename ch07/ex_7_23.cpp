#include <iostream>

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), content(h*w,'') {}
    Screen(pos h, pos w, char c): height(h), width(w), contents(h *w, c) {}
    char get() const
        { return contents[cursor];}
    inline char get(pos h, pos w) const;
    Screen& move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
