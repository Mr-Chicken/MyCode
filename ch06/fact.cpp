#include "Chapter6.h"

int fact(int a) {
	int ret = 1;
	while (a > 1)
		ret *= a--;
	return ret;
}