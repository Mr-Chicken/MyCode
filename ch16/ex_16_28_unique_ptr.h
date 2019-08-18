#ifndef EX_16_28_UNIQUE_PTR_H
#define EX_16_28_UNIQUE_PTR_H
#include <functional>

class Delete {
public:
	template <typename T> void operator()(T *p) const {delete p;}
};

template <typename T, typename Deleter> class UniquePtr;
template <typename T, typename Deleter = Delete>
bool operator!=(const UniquePtr<T, Deleter> &lhs, const UniquePtr<T, Deleter> &rhs);

template <typename T, typename Deleter =  Delete>
class UniquePtr {
	friend bool operator!=<T, Deleter>(const UniquePtr<T, Deleter> &lhs, const UniquePtr<T, Deleter> &rhs);
public:
	UniquePtr(T *p = nullptr, Deleter d = Delete()): ptr(p), dtr(d) {}
	~UniquePtr() {
		dtr(ptr);
	}
	UniquePtr(const UniquePtr &) = delete;
	UniquePtr& operator=(const UniquePtr &) = delete;
	UniquePtr(UniquePtr &&rhs) noexcept: ptr(rhs.ptr), dtr(std::move(rhs.dtr)) {rhs.ptr = nullptr;}
	UniquePtr& operator=(UniquePtr && rhs) noexcept {
		if (*this != rhs) {
			ptr = rhs.ptr;
			dtr = std::move(rhs.dtr);
			rhs.ptr = nullptr;
		}
		return *this;
	}
	UniquePtr& operator=(std::nullptr_t) {
		dtr(ptr);
		ptr = nullptr;
	}
	void swap(UniquePtr &rhs) {
		using std::swap;
		swap(ptr, rhs.ptr);
		swap(dtr, rhs.dtr);
	}
	T* release() {
		T* ret = ptr;
		dtr(ptr);
		return ret;
	}
	void reset(T *q = nullptr) {
		dtr(ptr);
		ptr = q;
	}
	T* get() const {return ptr;}
	T& operator*() {return *get();}
	T* operator->() {return get();}
	explicit operator bool() {
		return ptr != nullptr;
	}
private:
	T *ptr = nullptr;
	Deleter dtr;
};
template <typename T, typename Deleter =  Delete>
bool operator!=(const UniquePtr<T, Deleter> &lhs, const UniquePtr<T, Deleter> &rhs) {
	return lhs.ptr != rhs.ptr && lhs.dtr != rhs.dtr;
}
#endif