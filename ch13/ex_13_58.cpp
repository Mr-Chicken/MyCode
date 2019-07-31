#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};

Foo Foo::sorted() && {
	std::sort(data.begin(), data.end());
	cout << "sorted() &&" << endl;
	return *this;
}
// Foo Foo::sorted() const & {
// 	Foo ret(*this);
// 	// std::sort(ret.begin(), ret.end());
// 	cout << "sorted() const &" << endl;
// 	return ret.sorted();
// }

Foo Foo::sorted() const & {
	return Foo(*this).sorted();
}

int main() {
	Foo f;
	f.sorted();
	return 0;
}