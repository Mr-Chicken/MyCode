#include <iostream>
#include <string.h>
#include <memory>
using std::allocator;
using std::cout;
using std::endl;
using std::string;
using std::cin;
int main() {
	const size_t n = 10;
	allocator<string> alc;
	auto p = alc.allocate(10);
	string s;
	auto q = p;
	while (cin >> s && q != p + n) 
		alc.construct(q++, s);
	while (q != p) {
		cout << *q-- << endl;
		alc.destroy(q);
	}
	alc.deallocate(p, n);
	return 0;
}