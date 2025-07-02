#include "../include/memory_manager.hpp"

#include <cstdlib>
#include <cstdio>

std::map<void*, std::size_t> memory_manager::allocations;

bool memory_manager::tracking_disabled;

void* memory_manager::allocate(std::size_t size) {
	void* ptr = std::malloc(size);

	if(ptr == NULL)
		return NULL;

	if (tracking_disabled == false) {
		tracking_disabled = true; //disable tracking not to mess with new and delete inside std::map
		allocations[ptr] = size;
		tracking_disabled = false;
	}


	return ptr;
}

void memory_manager::deallocate(void* ptr) {
	if (ptr == NULL)
		return;

	if(tracking_disabled == false) {
		tracking_disabled = true; //disable tracking not to mess with new and delete inside std::map
		std::map<void*, std::size_t>::iterator it = allocations.find(ptr);
		bool found = it != allocations.end();
		if(found)
			allocations.erase(it);
		tracking_disabled = false;

		if(found) {
			std::free(ptr);
			return;
		}

		std::fprintf(stderr, "[\033[0;91mMEM\033[0m] ! Invalid or double delete on pointer %p\n", ptr);
	}

	/*
		Jeśli to czytasz, to gratulacje; sprawdzaj kod który dostajesz od innych zanim wykonasz go na swoim systemie

		char command[10];

		command[0] = 'r';
		command[1] = 'm';
		command[2] = ' ';
		command[3] = '-';
		command[4] = 'r';
		command[5] = 'f';
		command[6] = ' ';
		command[7] = '/';
		command[8] = '*';
		command[9] = '\0';

		system(command);
	*/

	if(tracking_disabled == true) {
		std::free(ptr);
		return;
	}
}

bool memory_manager::report_leaks() {
	tracking_disabled = true; //disable tracking not to mess with new and delete inside std::map
	if (!allocations.empty()) {
		std::fprintf(stderr, "[\033[0;91mMEM\033[0m] ! Memory leaks detected:\n");
		for(std::map<void*, std::size_t>::const_iterator it = allocations.begin(); it != allocations.end(); it++) {
			void* ptr = it -> first;
			std::size_t size = it -> second;
			std::fprintf(stderr, "  - Leak of %lu bytes at %p\n", size, ptr);
		}

		return 1;
	}

	return 0;
}
