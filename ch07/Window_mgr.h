#include "Screen.h"
#include <vector>

#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    Window_mgr::ScreenIndex addScreen(const Screen &sc);
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};

#endif
