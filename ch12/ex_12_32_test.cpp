#include "ex_12_32.h"

int main()
{
	std::ifstream is("infile");
	TextQuery tq(is);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(cout, tq.query(s));
	}
	return 0;
}