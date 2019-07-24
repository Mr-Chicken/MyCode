#include "ex_12_32.h"
inline std::string make_plural(size_t ctr, const std::string &word, const std::string &ending) {
    return (ctr > 1)? word + ending : word;
}

TextQuery::TextQuery(std::ifstream &is) {
	std::string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		std::stringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &s) {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, nodata, file);
	return QueryResult(s, loc->second, file);
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
	<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines) {
		StrBlobPtr p(qr.file, num);
		os << "\t(line " << num + 1 << ") " << p.deref() << endl; 
	}
	return os;
}


// from StrBlobPtr.cpp
shared_ptr<vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const {
	auto ret = wptr.lock();
	if (!ret) 
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() {
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

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}


const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
