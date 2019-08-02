#ifndef STRBLOB_H
#define STRBLOB_H
#include "StrBlobPtr.h"
#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <stdexcept>
using std::vector;
using std::initializer_list;
using std::string;
using std::shared_ptr;
using std::make_shared;

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const string &s) {data->push_back(s);}
	void pop_back();
	StrBlobPtr begin();
	StrBlobPtr end();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

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

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr	StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
#endif