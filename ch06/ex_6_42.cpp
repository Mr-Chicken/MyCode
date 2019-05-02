#include <iostream>

using std::endl;
using std::cout;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	string w1("success");
	string w2("failure");

	cout << make_plural(2,w1,"es") << endl;
	cout << make_plural(4,w2) << endl;
	return 0;
}