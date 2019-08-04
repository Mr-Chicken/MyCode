#ifndef STRBLOB_H
#define STRBLOB_H
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
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const {return data->size();}
	string& operator[](size_t n) {
		check(n, "out_of_range"); 
		return data->at(n);
	}
	const string& operator[](size_t n) const {
		check(n, "out_of_range");
		return data->at(n);
	}
	bool empty() const {return data->empty();}
	void push_back(const string &s) {data->push_back(s);}
	void pop_back();
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs);
}


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

#endif

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <string>
#include <vector>
using std::weak_ptr;
using std::string;
using std::shared_ptr;
using std::vector;
class StrBlob;

class StrBlobPtr {
	friend StrBlobPtr operator+(const StrBlobPtr &lhs, const size_t &rhs);
	friend StrBlobPtr operator-(const StrBlobPtr &lhs, const size_t &rhs);
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref();
	StrBlobPtr& incr();
	string& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	string* operator->() const {
		return &this->operator*();
	}
	string& operator[](size_t n) {
		return check(n, "out_of_range")->at(n);
	}
	const string& operator[](size_t n) const {
		return check(n, "out_of_range")->at(n);
	}
	StrBlobPtr& operator+=(size_t n) {
		check(curr, "increment past enf of StrBlobPtr");
		curr += n;
		return *this;
	}
	StrBlobPtr& operator-=(size_t n) {
		curr -= n;
		check(curr, "decrement past begin of StrBlobPtr");
	}
	StrBlobPtr& operator++() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
	StrBlobPtr operator++(int) {
		StrBlobPtr ret = *this;
		++*this;
		return ret;
	}
	StrBlobPtr& operator--() {
		--curr;
		check(curr, "decrement past begin of StrBlobPtr");
		return *this;
	}
	StrBlobPtr operator--(int) {
		StrBlobPtr ret = *this;
		--*this;
		return ret;
	}
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	bool ret = true;
	if (shared_ptr<vector<string>> lp = lhs.wptr.lock()) {
		shared_ptr<vector<string>> rp = rhs.wptr.lock();
		ret = (rp ? *lp == *rp : false);
	} 
	else
		return false;
	return ret && lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs == rhs);
}

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
StrBlobPtr StrBlob::begin() const{
	return StrBlobPtr(*this);
}
StrBlobPtr	StrBlob::end() const{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
StrBlobPtr operator+(const StrBlobPtr &lhs, const size_t &rhs) {
	StrBlobPtr ret = lhs;
	ret.check(lhs.curr, "increment past end of StrBlobPtr");
	ret.curr += rhs;
	return ret;
}
StrBlobPtr operator-(const StrBlobPtr &lhs, const size_t &rhs) {
	StrBlobPtr ret = lhs;
	ret.curr -= rhs;
	ret.check(ret.curr, "decrement past begin of StrBlobPtr");
	return ret;
}
#endif 


class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(0) {}
	const string& deref() const;
	ConstStrBlobPtr& incr();
	const string& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	const string* operator->() const {
		return &this->operator*();
	}
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};

