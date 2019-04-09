#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<unsigned> scores(11,0);
	unsigned grade;
	while (cin >> grade) {
		if (grade<=100){
			auto it = scores.begin() + grade/10;
			++(*it);
		}
	}
	for (auto x : scores) 
		cout << x << " ";
	cout << '\b' << endl;
	return 0;
}