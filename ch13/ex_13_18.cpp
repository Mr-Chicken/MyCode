#include <iostream>
using std::string;
class Employee {
public:
	Employee() = default;
	Employee(const string &n): name(n) {id = _id++;}
	Employee(const Employee &ep)w = delete;
	Employee& operator=(const Employee &ep) = delete;
private:
	string name;
	static int _id;
	int id;
};
int Employee::_id = 1;

int main()
{
	
	return 0;
}