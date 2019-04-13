#include <iostream>
using namespace std;

int main()
{
	short s = 32767;
	++s;
	unsigned us = 0;
	--us;
	unsigned short ush = 65535;
	++ush;
	cout << s << endl;	// -32768
	cout << us << endl;	// 4294967295
	cout << ush << endl;// 0
	return 0;
}