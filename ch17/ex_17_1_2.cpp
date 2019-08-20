#include <tuple>
#include <utility>
#include <string>
#include <vector>
using std::vector;
using std::pair;
using std::string;
using std::tuple;

int main()
{
	tuple<int, int, int> t{10, 20, 30};
	tuple<string ,vector<string>, pair<string, int>> t2 {"Hello", {"World"}, {"Tim", 19}};
	return 0;
}