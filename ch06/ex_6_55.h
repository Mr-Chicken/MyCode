#ifndef EX_6_55_H
#define EX_6_55_H
#include <vector>

int addition(const int &a, const int &b);
int subtraction(const int &a, const int &b);
int mucation(const int &a, const int &b);
int division(const int &a, const int &b);

using func = int (*)(const int&, const int&);
extern std::vector<func> v;

#endif