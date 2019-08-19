#ifndef EX_16_16_H
#define EX_16_16_H
#include <memory>
#include <initializer_list>
#include <utility>
using std::initializer_list;
template <typename T>
class Vec {
public:
	Vec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const initializer_list<T> &init);
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	~Vec();
	void push_back(const T&);
	template <typename... Args> void emplace_back(Args&&... args);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	T* begin() const {return elements;}
	T* end() const {return first_free;}
	void reverse(size_t n);
	void resize(size_t n);
	void resize(size_t n, const T &s);
private:
	std::allocator<T> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate();}
	std::pair<T*, T*> alloc_n_copy(const T *, const T *);
	void free();		// 销毁元素，释放内存
	void reallocate();	// 申请更多内存并拷贝已有元素
	T *elements;	// 指向数组首元素指针
	T *first_free;	// 指向数组最后以一个空闲元素指针
	T *cap;		// 指向数组尾后位置指针
};
#endif
template <typename T>
template <typename... Args> void Vec<T>::emplace_back(Args&&... args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
template <typename T>
void Vec<T>::free() {
	if (elements) {
		for (auto p = first_free; p != elements; alloc.destroy(--p));
		alloc.deallocate(elements, cap - elements);
	}
}
template <typename T>
void Vec<T>::push_back(const T &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
template <typename T>
Vec<T>::Vec(const Vec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::Vec(const initializer_list<T> &init) {
	auto newData = alloc_n_copy(init.begin(), init.end());
	elements = newData.first;
	first_free = cap = newData.second;
}
template <typename T>
Vec<T>::~Vec() {
	free();
}
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template <typename T>
void Vec<T>::reallocate() {
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
template <typename T>
void Vec<T>::reverse(size_t n) {
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
template <typename T>
void Vec<T>::resize(size_t n) {
	resize(n, T());
}
template <typename T>
void Vec<T>::resize(size_t n, const T &s) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	} else if (n > size()) {
		reverse(n * 2);
		for (size_t i = 0; i < n; ++i)
			alloc.construct(first_free++, s);
	}
}

#ifndef EX_13_39_H
#define EX_13_39_H
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>
using std::string;
using std::initializer_list;

class StrVec {
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const initializer_list<string> &init);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	template <typename... Args> void emplace_back(Args&&... args);
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

#endif
template <typename... Args>
void StrVec::emplace_back(Args&&... args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
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

