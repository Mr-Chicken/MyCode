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
	return s.size() <= sz;
}


int main()
{
	vector<string> vec {"apple", "banana", "cabbage"};
	cout << std::count_if(vec.begin(), vec.end(), std::bind(check_size, _1, 6)) << endl;

	return 0;
}