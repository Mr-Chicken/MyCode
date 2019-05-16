#include "Screen.h"
#include "Window_mgr.h"
#include <iostream>

int main() {
    Screen s1(5, 5, 'X');
    Screen s2(3, 3, 'Y');

    Window_mgr mgr;
    mgr.addScreen(s1);
    mgr.addScreen(s2);
    s1.display(std::cout);
    s2.display(std::cout);

    mgr.clear(1);

    s1.display(std::cout);
    s2.display(std::cout);

    return 0;
}
