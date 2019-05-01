#include <iostream>
using std::cout;
using std::endl;
using std::string;
int main(int argc, char *argv[]) {
	string s;
	s += argc;
	for (int i = 0; i< argc; ++i) {
		s += argv[i];
	}
	cout << s << endl;
}