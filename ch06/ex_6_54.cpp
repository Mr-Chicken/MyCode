#include <vector>

int func(int, int);

using pFunc = int (*)(int, int);
using declFunc = decltype(func)*;
typedef int (*pFunc2)(int, int);
std::vector<pFunc> v1;
std::vector<pFunc2> v2;
std::vector<declFunc> v;