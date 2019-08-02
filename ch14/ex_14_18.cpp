#include <algorithm>
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
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator< (const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator> (const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const {return data->size();}
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
bool operator< (const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data < *rhs.data;
}
bool operator> (const StrBlob &lhs, const StrBlob &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data <= *rhs.data;
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
	return rhs <= lhs;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
	return lhs.data == rhs.data;
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
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator< (const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator> (const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref();
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};
bool operator< (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr < rhs.curr;
}
bool operator> (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs.curr < rhs.curr);
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr <= rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs.curr <= rhs.curr);
}

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
#endif 

#ifndef EX_13_39_H
#define EX_13_39_H
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>
using std::string;
using std::initializer_list;

class StrVec {
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const initializer_list<string> &init);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	string* begin() const {return elements;}
	string* end() const {return first_free;}
	void reverse(size_t n);
	void resize(size_t n);
	void resize(size_t n, const string &s);
private:
	std::allocator<string> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate();}
	std::pair<string*, string*> alloc_n_copy(const string *, const string *);
	void free();		// 销毁元素，释放内存
	void reallocate();	// 申请更多内存并拷贝已有元素
	string *elements;	// 指向数组首元素指针
	string *first_free;	// 指向数组最后以一个空闲元素指针
	string *cap;		// 指向数组尾后位置指针
};
bool operator<(const StrVec &lhs, const StrVec &rhs) {
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
bool operator>(const StrVec &lhs, const StrVec &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs < rhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs > rhs);
}
bool operator==(const StrVec &lhs, const StrVec &rhs) {
	return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free && lhs.cap == rhs.cap
		&& lhs.alloc == rhs.alloc;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}
std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements; alloc.destroy(--p));
		alloc.deallocate(elements, cap - elements);
	}
}
void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(const initializer_list<string> &init) {
	auto newData = alloc_n_copy(init.begin(), init.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec::~StrVec() {
	free();
}
StrVec& StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	auto newCapacity = size() ? size()*2 : 1;
	auto newData = alloc.allocate(newCapacity);
	auto dest = newData;		// 指向新数组的下一空闲位置
	auto elem = elements;		// 指向旧数组的下一元素
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}
void StrVec::reverse(size_t n) {
	if (n <= capacity()) return ;
	auto newData = alloc.allocate(n);
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i<=size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	elements = newData;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(size_t n) {
	resize(n, string());
}
void StrVec::resize(size_t n, const string &s) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	} else if (n > size()) {
		reverse(n * 2);
		for (size_t i = 0; i < n; ++i)
			alloc.construct(first_free++, s);
	}
}
#endif
#ifndef STRING_H
#define STRING_H
#include <memory>
#include <utility>
using std::allocator;
class String {
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);
public:
	String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char *str);
	String(const String &s);
	~String();
	String& operator=(const String &s);
	char* begin() const {return elements;}
	char* end() const {return first_free;}
	size_t size() {return first_free - elements;}
	size_t capacity() {return cap - elements;}
private:
	allocator<char> alloc;
	std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
	void free();		// 销毁元素并释放内存
	void reallocate();	// 获得更多内存并拷贝已有内存
	char *elements;		// 该数组首元素
	char *first_free;	// 该数组第一个空闲位置
	char *cap;			// 该数组尾后指针
};
bool operator<(const String &lhs, const String &rhs) {
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
bool operator>(const String &lhs, const String &rhs) {
	return !(lhs < rhs);
}
bool operator<=(const String &lhs, const String &rhs) {
	return !(lhs < rhs);
}
bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs > rhs);
}
bool operator==(const String &lhs, const String &rhs) {
	return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free && lhs.cap == rhs.cap
		&& lhs.alloc == rhs.alloc;
}
bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);;
}
void String::free() {
	if (elements) {
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
String::~String() {
	free();
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
	auto newData = alloc.allocate(e - b);
	return {newData, std::uninitialized_copy(b, e, newData)};
}

void String::reallocate() {
	auto newCapacity = size() ? size() * 2 : 1;
	auto newData = alloc.allocate(newCapacity);
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}
String::String(const String &s) {
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

String& String::operator=(const String &s) {
	auto newData = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	return *this;
}

String::String(const char *str) {
	char *s = const_cast<char*>(str);
	while (*s)
		++s;
	auto newData = alloc_n_copy(str, ++s);
	elements = newData.first;
	first_free = cap = newData.second;
}
#endif
