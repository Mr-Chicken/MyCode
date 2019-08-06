#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
class SizeComp {
public:
	SizeComp(size_t size): sz(size) {}
	bool operator()(const string &s) const {
		return s.size() == sz;
	}
private:
	size_t sz;
};

int main()
{
	vector<string> vec;
	ifstream is("word");
	size_t size = 1;
	string word;
	while (is >> word)
		vec.push_back(word);
	while (size <= 10) {
		size_t num = std::count_if(vec.begin(), vec.end(), SizeComp(size));
		cout << "The length of word >= " << size << " occurs " << num << endl;
		++size;
	}
	return 0;
}