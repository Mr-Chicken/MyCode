#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
// from StrBlob.h
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
using std::ifstream;
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

// from StrBlob.cpp
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

// from StrBlobPtr.h
class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	bool operator!=(const StrBlobPtr &p) {return curr != p.curr;}
	string& deref();
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};

// from StrBlobPtr.cpp
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

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr	StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
int main()
{
	// Exercise 12.20
	StrBlob sb;
	ifstream in("file");
	string line;
	while (std::getline(in, line))
		sb.push_back(line);
	in.close();

	for (StrBlobPtr beg = sb.begin(), end = sb.end(); beg != end; beg.incr())
		cout << beg.deref() << endl;
	return 0;
}