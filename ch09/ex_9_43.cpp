#include <iostream>
using std::cout;
using std::endl;
using std::string;
void replaceStr(string &s, const string &oldVal, const string &newVal) {
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (oldVal == string(it, it+oldVal.size())) {
			it = s.erase(it, it + oldVal.size());
			it = s.insert(it, newVal.begin(), newVal.end());
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