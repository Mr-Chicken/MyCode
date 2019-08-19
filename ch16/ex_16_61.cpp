#ifndef EX_16_28_SHARED_PTR_H
#define EX_16_28_SHARED_PTR_H

#include <functional>
template <typename T>
class SharedPtr {
	using Deleter = std::function<void(T*)>;
public:
	SharedPtr(): dter(nullptr), count(new size_t(1)), ptr(new T) {}
	SharedPtr(T *p, Deleter d = nullptr): ptr(p), dter(d), count(new size_t(1)) {}
	~SharedPtr() {
		if (!ptr) return;
		if (--*count == 0) {
			dter ? dter(ptr) : delete ptr;
			delete count;
		}
		ptr = nullptr;
		count = nullptr;
	}
	SharedPtr(const SharedPtr &sp): dter(sp.dter), count(sp.count), ptr(sp.ptr)
		{++*count;}
	SharedPtr& operator=(SharedPtr rhs) {
		swap(*this, rhs);
		return *this;
	}
	void reset(T *p = nullptr, Deleter d = nullptr) {
		*count = 1;
		ptr = p;
		dter = d;
	}
	void swap(SharedPtr &sp) {
		using std::swap;
		swap(dter, sp.dter);
		swap(count, sp.count);
		swap(ptr, sp.ptr);
	}
	T* get() const {return ptr;}
	T& operator*() {
		return *get();
	}
	T* operator->() {
		return get();
	}
	size_t use_count() const {
		return *count;
	}
	explicit operator bool() const {
		return ptr != nullptr;
	} 
private:
	Deleter dter = nullptr;
	size_t *count;
	T *ptr = nullptr;
};

template <typename T, typename... Args>
SharedPtr<T> makeShared(Args&&... args) {
	return SharedPtr<T>(new T(std::forward<Args>(args)...));
}
#endif