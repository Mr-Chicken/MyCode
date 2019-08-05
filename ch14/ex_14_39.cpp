#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

class isInRange {
public:
	isInRange(size_t low, size_t up): lowest(low), uppest(up) {}	// 记录lower到uppest的值
	isInRange(size_t low): lowest(low), uppest(0) {}				// 无上限且最少低于lowest的值
	bool operator()(const string &s) const {
		if (uppest == 0)
			return s.size() >= lowest;
		return s.size() >= lowest && s.size() <= uppest;
	}
private:
	size_t lowest;
	size_t uppest;
};

int main()
{
	vector<string> vec;
	ifstream is("word");
	for (string word; is >> word; )
		vec.push_back(word);

	cout << "The word between 1 to 9 occurs " << std::count_if(vec.begin(), vec.end(), isInRange(1, 9)) << endl;
	cout << "The word upper 10 occurs " << std::count_if(vec.begin(), vec.end(), isInRange(10)) << endl;
	return 0;
}