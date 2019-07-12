#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::istream_iterator;
int main()
{
	ifstream file("afile");

	if (!file.is_open())
		return -1;

	istream_iterator<string> imt(file);
	istream_iterator<string> eof;
	vector<string> vec(imt, eof);

	for (const auto &x : vec) 
		cout << x << " ";
	cout << endl;
	return 0;
}