#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

int main()
{
	vector<string> vec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "thurtle"};
	elimDups(vec);
	for (const auto &x : vec) 
		cout << x << " ";
	cout << endl;
	return 0;
}