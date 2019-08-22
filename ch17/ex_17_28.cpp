#include <random>
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;

inline unsigned getNumber() {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(1, 1000);
	return u(e);
}
inline unsigned getNumber(unsigned seed) {
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(1, 1000);
	return u(e);
}
inline unsigned getNumber(unsigned min, unsigned max, unsigned seed) {
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}
int main()
{
	for (int i = 1; i <=100; ++i)
		cout << getNumber(0, 10000, time(0)) << endl;
	return 0;
}