#include <vector>
#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cin;
using std::cout;
using std::vector;
using std::endl;

shared_ptr<vector<int>> createVector() {
	return std::make_shared<vector<int>>();
}

void read(shared_ptr<vector<int>> &vec) {
	int a;
	while (cin >> a)
		vec->push_back(a);
}

void print(const shared_ptr<vector<int>> &vec) {
	for (const auto &x : *vec)
		cout << x << " ";
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> vec = createVector();
	read(vec);
	print(vec);
	return 0;
}