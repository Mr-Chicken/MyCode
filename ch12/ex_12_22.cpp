#include "ex_12_22.h"

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}


const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

ConstStrBlobPtr StrBlob::begin() const{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr	StrBlob::end() const{
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

const string& ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr() {
	check(curr, "incrememt past end of StrBlobPtr");
	++curr;
	return *this;
}