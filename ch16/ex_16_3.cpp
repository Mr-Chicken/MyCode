#include "../ch08/Sales_data.h"

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0; 
}
int main()
{
	compare(Sales_data(), Sales_data());
	/*
	In instantiation of 'int compare(const T&, const T&) [with T = Sales_data]':
	.\ex_16_3.cpp:11:36: required from here
	error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
  	if (v1 < v2) return -1;
    	~~~^~~~
	error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
  	if (v2 < v1) return 1;
     	~~~^~~~
	*/
	return 0;
}