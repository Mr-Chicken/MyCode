#include <typeinfo>
#include <iostream>
#include "../ch08/Sales_data.h"
using std::cout;
using std::endl;

class Base {
public:
	virtual ~Base(){}
};
class Derived : public Base{
public:
	virtual ~Derived(){}
};
int main()
{
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << typeid(42).name() << ", " 
		 << typeid(arr).name() << ", "
		 << typeid(Sales_data).name() << ", "
		 << typeid(std::string).name() << ", "
		 << typeid(p).name() << ", "
		 << typeid(*p).name() << endl;
	return 0;
}