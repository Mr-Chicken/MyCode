#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

vector<int>* createVector() {
	return new vector<int>;
}
void read(vector<int> *vec) {
	int a;
	while (cin >> a)
		vec->push_back(a);
}
void print(const vector<int> *vec) {
	for (const auto &x : *vec)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<int> *vec = createVector();
	read(vec);
	print(vec);

	delete vec;
	return 0;
}