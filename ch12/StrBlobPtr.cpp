#include "StrBlobPtr.h"

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret) 
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
}