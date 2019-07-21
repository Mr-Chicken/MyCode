#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main() {
	string word;
	const size_t sz = 32;
	char *buf = new char[sz+1];
	cin.get(buf, sz+1);
	cout << buf << endl;
	delete []buf;
	return 0;
}