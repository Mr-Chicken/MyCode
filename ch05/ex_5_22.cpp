#include <iostream>
using std::cout;
using std::endl;

int get_size() {
	return 52*10e1;
}

int main()
{
	while (get_size() <= 0); // do sth
	return 0;
}
