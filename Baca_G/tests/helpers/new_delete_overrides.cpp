#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"

#include <new>

//scalar new and delete
void* operator new(std::size_t size) throw(std::bad_alloc) {
	void* ptr = memory_manager::allocate(size);
	if (!ptr) throw std::bad_alloc();
	return ptr;
}

void operator delete(void* ptr) throw() {
	memory_manager::deallocate(ptr);
}


//array new and delete
void* operator new[](std::size_t size) throw(std::bad_alloc) {
	void* ptr = memory_manager::allocate(size);
	if (!ptr) throw std::bad_alloc();
	return ptr;
}

void operator delete[](void* ptr) throw() {
	memory_manager::deallocate(ptr);
}


//nothrow variants
void* operator new(std::size_t size, const std::nothrow_t&) throw() {
	return memory_manager::allocate(size);
}

void operator delete(void* ptr, const std::nothrow_t&) throw() {
	memory_manager::deallocate(ptr);
}

void* operator new[](std::size_t size, const std::nothrow_t&) throw() {
	return memory_manager::allocate(size);
}

void operator delete[](void* ptr, const std::nothrow_t&) throw() {
	memory_manager::deallocate(ptr);
}
