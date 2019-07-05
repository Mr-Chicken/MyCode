#include <iostream>
using std::cout;
using std::endl;
using std::string;
void replaceStr(string &s, const string &oldVal, const string &newVal) {
	for (string::size_type x = 0; x < s.size(); ++x) {
		if (oldVal == string(s, x, x+oldVal.size())) {
			s.replace(x, oldVal.size(), newVal);
		}
	}
}


int main()
{
	string s("tho thru");
	replaceStr(s, "tho", "though");
	cout << s << endl;
	replaceStr(s, "thru", "throught");
	cout << s << endl;
	return 0;
}