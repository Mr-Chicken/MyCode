#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<string> vec {"56", "93", "91", "88", "12", "54", "49"};
	int sum = 0;
	for (const auto &x : vec)
		sum += stoi(x);
	cout << sum << endl;
	return 0;
}