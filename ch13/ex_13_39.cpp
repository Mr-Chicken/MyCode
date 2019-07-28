#include "ex_13_39.h"

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

