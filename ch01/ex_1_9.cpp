#include <iostream>
using std::cout;
using std::endl;

int main() {
    int sum,n = 50;
    while (n<=100) {
	sum += n;
	++n;
    } 
    cout << "The sum of 50 to 100 is " << sum <<endl;
    return 0;
}
