#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main() {
	string str = "ab2c3d7R4E6";
	string c = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string::size_type pos = 0;
	while ((pos = str.find_first_of(c, pos)) != string::npos) {
		cout << "found number at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(c, pos)) != string::npos) {
		cout << "found number at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}
	return 0;
}