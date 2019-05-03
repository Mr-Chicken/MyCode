#include "ex_6_55.h"

int addition(const int &a, const int &b) {
	return a + b;
}

int subtraction(const int &a, const int &b) {
	return a - b;
}

int mucation(const int &a, const int &b) {
	return a * b;
}

int division(const int &a, const int &b) {
	if (b == 0) 
		return 0;
	return a / b;
}