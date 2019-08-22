#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
int main()
{
	char sink[256];
	ifstream in("data");
	while (in.getline(sink, 256, ' '))
		cout << sink << endl;

	return 0;
}