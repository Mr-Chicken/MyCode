#include <fstream>
#include <iostream>
#include <iterator>

using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char const *argv[])
{
	ifstream in(argv[1]);
	ofstream odd(argv[2]);
	ofstream even(argv[3]);
	istream_iterator<int> int_iter(in), eof;
	ostream_iterator<int> odd_int(odd, " ");
	ostream_iterator<int> even_int(even, "\n");

	while (int_iter != eof) {
		if (*int_iter % 2)
			odd_int = *int_iter;
		else
			even_int = *int_iter;
		++int_iter;
	}
	return 0;
}