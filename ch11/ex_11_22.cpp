#include <map>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::map;

map<string, vector<int>> m;
m.insert({"A", 1});
/*
	参数类型: pair<string, vector<int>>
	返回类型: pair<map<string, vector<int>::iterator, bool> 
*/
