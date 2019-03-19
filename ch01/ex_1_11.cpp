#include <iostream>
using std::cout;
using std::endl;

int main() {
    int val1,val2;

    cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    
    if (val1 < val2) {
	++val1; // 使他不包括自己
	while (val1 < val2) {
	    cout << val1++ << endl;
	}
    } else {
	++val2;
	while (val1 > val2) {
	    cout << val2++ << endl;
	}
    }
}   
