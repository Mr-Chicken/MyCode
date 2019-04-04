#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main(int argc, char const *argv[])
{
	// like that
	std::vector<int> ivec(1);
	ivec[0] = 42;
	// or "std::vector<int> ivec{42}"
	return 0;
}