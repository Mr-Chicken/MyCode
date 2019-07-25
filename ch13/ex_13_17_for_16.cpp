#include <iostream>
using std::cout;
using std::endl;

class numbered {
public:
	numbered() {mysn = unique++;}
	numbered(const numbered &n) {mysn = unique++;}
	int mysn;
	static int unique;
};
int numbered::unique = 1;

void f(const numbered &s) {cout << s.mysn << endl;}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}