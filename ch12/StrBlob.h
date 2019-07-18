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

class StrBlob {
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const string &s) {data->push_back(s);}
	void pop_back();

	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

#endif