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
	StrVec& operator=(const initializer_list<string> &il);
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
StrVec& StrVec::operator=(const initializer_list<string> &il) {
	auto newData = alloc_n_copy(il.begin(), il.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	return *this;
}

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