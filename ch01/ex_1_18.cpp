#include <iostream>

using namespace std;
int main() {
    int currVal ,val =0;
    
    if (cin >> currVal) {
	int cnt = 1;
	while (cin >> val) {
	    if (currVal == val) {
		cnt++;
	    } else {
		cout << currVal << " occurs " << cnt << " times" << endl;
		cnt = 1;
		currVal = val;
	    }	    
	}
    }
    return 0;
}
