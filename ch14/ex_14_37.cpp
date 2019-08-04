#include <algorithm>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class equal
{
public:
	equal(int n = 0): num(n) {}
	bool operator()(int a) {
		return a == num;
	}
private:
	int num;
};

int main()
{
	vector<int> vec {5,5,5,5,5,5,5,5};
	std::replace_if(vec.begin(), vec.end(), equal(5), 2);
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
	return 0;
}