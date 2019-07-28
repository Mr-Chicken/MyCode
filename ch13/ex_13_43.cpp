void StrVec::free() {
	if (elements) {
		std::for_each(first_free, elements, [this](char &c) {
			alloc.destory(&c);
		});
		alloc.deallocate(elements, cap - elements);
	}
}