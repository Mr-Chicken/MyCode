#ifndef EX_12_32_H
#define EX_12_32_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <initializer_list>
#include <vector>
#include <memory>
#include <stdexcept>
#include <set>
#include <map>
using std::map;
using std::set;
using std::vector;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

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

// from StrBlobPtr.h
class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	bool operator!=(const StrBlobPtr &p) {return curr != p.curr;}
	string& deref();
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};

using line_no = StrBlob::size_type;
class QueryResult ;
class TextQuery {
public:
	TextQuery(std::ifstream &is);
	QueryResult query(const string &s);
private:
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
	friend std::ostream& print(std::ostream& os, const QueryResult &qr);
public:
	QueryResult(const string &s, shared_ptr<set<line_no>> p, StrBlob f):
		sought(s), file(f), lines(p){}
private:
	string sought;
	StrBlob file;
	shared_ptr<set<line_no>> lines;
};
#endif