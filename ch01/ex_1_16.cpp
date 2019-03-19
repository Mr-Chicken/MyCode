#include <iostream>
using namespace std;
int main() {
    int sum = 0,value =0;
    std::cout << "Use Control+D(Linux) to stop:";
    while (std::cin >> value) { 
	sum += value;
    }
    cout << "The sum is " << sum <<endl;
    return 0;
}
