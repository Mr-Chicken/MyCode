#include <iostream>
using namespace std;

int main() {
    const int i = 42;
    auto j = i; // j is an int
    const auto &k = i; auto *p = &i; // k i const int&,p is a const int*
    const auto j2 = i, &k2 = i;  // j2 is a const int,k2 is a const int&
    return 0;
}
