#ifndef EX_12_22_H
#define EX_12_22_H

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
using std::weak_ptr;

class ConstStrBlobPtr;
class StrBlob {
	friend class ConstStrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const string &s) {data->push_back(s);}
	void pop_back();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(0) {}
	const string& deref() const;
	ConstStrBlobPtr& incr();
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};
#endif