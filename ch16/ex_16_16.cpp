#include "ex_16_16.h"
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

