#include <iostream>

using namespace std;

int main() {
    int v1,v2;
    cin >> v1 >> v2;
    if (v1 > v2) {
	while (v1>v2) {
	    cout << --v1 << endl;
	}
    } else {
	while (v1<v2) {
	    cout << ++v1 << endl;
	}
    }
    return 0;
}
