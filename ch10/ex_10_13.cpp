#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool moreThanFive(const string &s) {
	return s.size() >= 5;
}

int main()
{
	vector<string> vec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "thurtle"};
	auto end_five = std::partition(vec.begin(), vec.end(), moreThanFive);
	for (auto it = vec.cbegin(); it != end_five; ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}