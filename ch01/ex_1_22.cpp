#include <iostream>
#include "Sales_item.h"

using namespace std;
int main() {
    Sales_item sum;
    Sales_item cur;
    cin >> sum;
    while (cin >> cur) {
	if (sum.isbn() == cur.isbn()) {
	    sum += cur;
	} else {
	    cout << "ISBN different!" << endl;
	}
    }
    cout << sum << endl;
    return 0;
}
