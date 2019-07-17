#include <map>
#include <iostream>
#include <vector>
using std::map;
using std::vector;
using std::string;

int main()
{
	map<string, vector<int>> m {
		{"A", {1,2,3}},
		{"B", {4,5,6}}
	};

	// Exercise 11.28
	map<string, vector<int>>::iterator it = m.find("A");
	
	// Exercise 11.29
	/* 
		如果关键词是map中最大关键词，则upper_bound lower_bound 都返回尾后迭代器。equal_range 返回一个迭代器 pair，
	它的两个元素都是 cend()
	 */

	// Exercise 11.30
	/*
		pos 为pair类型，它的两个元素分别与 lower_bound 和 upper_bound 相同 (pair)
		pos.first 代表 lower_bound 返回的元素 (迭代器)
		pos.first->second 代表与 search_item 关键字映射的第一个值
	*/
	return 0;
}