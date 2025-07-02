//scalar new and delete
void* operator new(std::size_t size) throw(std::bad_alloc);
void  operator delete(void* ptr) throw();

//array new and delete
void* operator new[](std::size_t size) throw(std::bad_alloc);
void  operator delete[](void* ptr) throw();

//nothrow variants
void* operator new(std::size_t size, const std::nothrow_t&) throw();
void  operator delete(void* ptr, const std::nothrow_t&) throw();

void* operator new[](std::size_t size, const std::nothrow_t&) throw();
void  operator delete[](void* ptr, const std::nothrow_t&) throw();
