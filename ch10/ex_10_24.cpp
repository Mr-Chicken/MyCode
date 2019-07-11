#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
	return s.size() < sz;
}


int main()
{
	string s = "apple";
	vector<int> nums {1,2,3,4,5,6,7};
	auto it = std::find_if(nums.begin(), nums.end(), bind(check_size, s, _1));
	cout << *it << endl;
	return 0;
}