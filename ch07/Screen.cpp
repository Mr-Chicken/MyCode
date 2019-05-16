#include "Screen.h"

inline char Screen::get(pos r, pos c) const {
    pos row = r*width;
    return contents[row+c];
}

inline Screen& Screen::move(pos r, pos c) {
    pos row = r*width;
    cursor = row + c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
    pos row = r*width;
    contents[row + c] = ch;
    return *this;
}
inline Screen& Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
