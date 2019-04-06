#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int count = 1;
template <typename T>
void listVector(vector<T> &vec) {
	cout << "Vector " << count++ << " size: " << vec.size() << " values: ";
	for (auto it = vec.cbegin();it != vec.cend();++it)
		cout << *it << " ";
	cout << '\b' << endl;
}

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};

	listVector<int>(v1);
	listVector<int>(v2);
	listVector<int>(v3);
	listVector<int>(v4);
	listVector<int>(v5);
	listVector<string>(v6);
	listVector<string>(v7);
	return 0;
}