#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
    // 1.9
    int i = 50;
    int sum = 0;
    while (i<=100) {
	sum += i++;
    }
    cout << sum << endl;
    // 1.10
    for (int i = 10;i>=1;--i) 
	cout << i-1 << endl;
    // 1.11 simple
    cout << "Enter two numbers: ";
    int j = 0,k =0;
    cin >> j >> k;
    while (j>k) {
	cout << --j << endl;
    }
    return 0;
}
