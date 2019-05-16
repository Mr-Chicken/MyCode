#include "Window_mgr.h"


void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &sc) {
    screens.push_back(sc);
    return screens.size() - 1;
}
