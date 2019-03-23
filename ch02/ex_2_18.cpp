#include <iostream>
using namespace std;

int main() {
    int a = 10,b = 20;
    int *p = &a;
    cout << "a = " << *p << endl;
    p = &b;
    cout << "b = " << *p << endl;
    *p = 10000;
    cout << "b = " << b << endl;
    return 0;
}
