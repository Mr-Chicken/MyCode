#include "String.h"

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