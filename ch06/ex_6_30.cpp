#include <string>
using std::string;
bool str_subrange(const string &str1, const string &str2) {
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()? str1.size(): str2.size());
	for (decltype(size) i = 0; i < size;++i) {
		if (str1[i] != str2[i])
			return;
	}
}

/*
ex_6_30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
ex_6_30.cpp:9:4: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
    return;
    ^~~~~~

*/