#include <functional>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using namespace std::placeholders;
int main()
{
	// (a)
	vector<int> vec {1,2,3,4,1025};
	cout << std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), _1, 1024)) << endl;
	// (b)
	vector<string> word {"pop", "pooh"};
	std::find_if(word.begin(), word.end(), std::bind(std::not_equal_to<string>(), _1, "pooh"));
	// (c)
	vector<int> iv;
	std::transform(vec.begin(), vec.end(), std::back_inserter(iv), std::bind(std::multiplies<int>(), _1, 2));
	return 0;
}