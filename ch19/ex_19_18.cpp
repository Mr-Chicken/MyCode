#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <functional>
using std::vector;
using std::count_if;
using std::cout;
using std::endl;
using std::string;

int report(const vector<string> &vec) {
	return count_if(vec.begin(), vec.end(), std::mem_fn(&string::empty));
}

int main()
{
	vector<string> vec {"", "", "", "A"};
	cout << report(vec) << endl;
	return 0;
}