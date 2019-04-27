#include <iostream>
using std::cout;
using std::endl;
using std::string;
int main()
{
	const string text("helloworld");

	for (auto it = text.end()-1;it != text.begin()-1;--it) {
		cout << *it << endl;
	}

	auto it = text.end() - 1;
	auto beg = text.begin() - 1;
	while (it != beg) {
		cout << *it << endl;
		--it;
	}
	return 0;
}
