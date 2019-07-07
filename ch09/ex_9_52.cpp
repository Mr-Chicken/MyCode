#include <stack>
#include <iostream>
using std::cout;
using std::endl;
using std::stack;
using std::string;
/**
	未完成！！！！
*/

int main()
{
	string expr = "I'm (young)";
	stack<char> sk;
	bool valueSaw = false;
	string value;
	for (const auto &x : expr) {
		if (x == '(') {
			sk.push(x); 
			valueSaw = true;
			continue;
		}
		else if (x == ')'){
			sk.pop();
			valueSaw = false;
			continue;
		}
		if (valueSaw) value += x;
	}
	string::size_type start = expr.find(value) - 1;
	string::size_type end = start + expr.size() + 3;
	expr.replace(start, end, value);

	cout << expr << endl;
	return 0;
}