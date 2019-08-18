#include "ex_16_28_shared_ptr.h"
#include "ex_16_28_unique_ptr.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	SharedPtr<int> p(new int(2));
	UniquePtr<int, std::function<void(int*)>> up(new int(3), [](int *p) {
		cout << "lambda delete" << endl;
		delete p;
	});
	cout << *p << endl;
	return 0;
}