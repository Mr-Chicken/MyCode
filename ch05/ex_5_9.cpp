#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned vowel = 0;

	char ch;

	while (cin >> ch) {
		switch (ch) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++vowel;
				break;
		}
	}

	cout << vowel << endl;

	return 0;
}