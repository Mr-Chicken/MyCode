#include <iostream>
#include <vector>
#include <fstream>
using std::istream;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
class ReadString {
public:
	ReadString(istream &i): is(i) {}
	string operator()() const {
		string ret;
		getline(is, ret);
		return is ? ret : string();
	}
private:
	istream &is;
};

int main()
{
	ReadString read(cin);
	vector<string> vec;
	string cur;
	while ((cur = read()) != string())
		vec.push_back(cur);
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
	return 0;
}