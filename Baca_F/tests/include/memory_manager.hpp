#include <map>

class memory_manager {
public:
	static void* allocate(std::size_t size);
	static void deallocate(void* ptr);
	static bool report_leaks();

private:
	static std::map<void*, std::size_t> allocations;
	static bool tracking_disabled;
};
