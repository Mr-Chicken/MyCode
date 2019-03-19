#include <iostream>
using namespace std;

auto fromFiftyToOneHundred() {
    int sum = 0;
    for (int i = 50;i <=100;i++) {
	sum += i;
    }
    return sum;
}
void fromTenToZero() {
    for (int i = 10-1;i >0;--i) {
	cout << i << endl;
    }
}
void getInterval() {
    int v1,v2;
    cout << "Enter two numbers: ";
    cin >> v1 >> v2;
    for (;v1<v2;++v1) {
	cout << v1 << endl;
    }
}

int main() {
    getInterval();
    cout << "fromFiftyToOneHundred: " << fromFiftyToOneHundred() << endl;
    cout << "fromTenToZero: "<<endl;
    fromTenToZero();
    return 0;
}
