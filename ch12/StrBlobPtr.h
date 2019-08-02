#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include "StrBlob.h"
#include <memory>
#include <string>
#include <vector>
using std::weak_ptr;
using std::string;
using std::shared_ptr;
using std::vector;
class StrBlob;


class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) {}
	
	StrBlobPtr(StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref();
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};

#endif 