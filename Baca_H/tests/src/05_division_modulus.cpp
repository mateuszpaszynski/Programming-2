#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	std::cout << "TESTY ZNALEZIONE NA DISCORDZIE @rudejestwredne" << std::endl;

	std::cout << (POLYNOMIAL() / POLYNOMIAL(0, 1)) <<  " ( 0 )" << std::endl;
	std::cout << (POLYNOMIAL() % POLYNOMIAL(0, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 1, -2, 1) / POLYNOMIAL(2, 1, -2, 1)) <<  " ( 1 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 1, -2, 1) % POLYNOMIAL(2, 1, -2, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(0, 1) / POLYNOMIAL(0, 1)) <<  " ( 1 )" << std::endl;
	std::cout << (POLYNOMIAL(0, 1) % POLYNOMIAL(0, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(0, 1)) <<  " ( 2, 3, 5, 7, 11 )" << std::endl;
	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) % POLYNOMIAL(0, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, 1, 1)) <<  " ( -6, 9, -4, 11 )" << std::endl;
	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) % POLYNOMIAL(1, 1, 1)) <<  " ( 1 )" << std::endl;

	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, -1, -1)) <<  " ( 6, -9, 4, -11 )" << std::endl;
	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) % POLYNOMIAL(1, -1, -1)) <<  " ( 1 )" << std::endl;

	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, 0, 1)) <<  " ( 3, 5, 7, 11 )" << std::endl;
	std::cout << (POLYNOMIAL(4, 2, 3, 5, 7, 11) % POLYNOMIAL(1, 0, 1)) <<  " ( 1 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 1, 1, -2) / POLYNOMIAL(1, -1, 1)) <<  " ( -1, -2 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 1, 1, -2) % POLYNOMIAL(1, -1, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 1, 1, -2) / POLYNOMIAL(0, -1)) <<  " ( -1, -1, 2 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 1, 1, -2) % POLYNOMIAL(0, -1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 1, 1, 2) / POLYNOMIAL(1, -1, 1)) <<  " ( 3, 2 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 1, 1, 2) % POLYNOMIAL(1, -1, 1)) <<  " ( 1 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 1, 4, 2) / POLYNOMIAL(1, 1, 1)) <<  " ( 1, 1 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 1, 4, 2) % POLYNOMIAL(1, 1, 1)) <<  " ( -1 )" << std::endl;

	std::cout << (POLYNOMIAL(2, 2, 3, 5) / POLYNOMIAL(1, 1, 7)) <<  " ( 16, 35 )" << std::endl;
	std::cout << (POLYNOMIAL(2, 2, 3, 5) % POLYNOMIAL(1, 1, 7)) <<  " ( 1 )" << std::endl;

	std::cout << (POLYNOMIAL() / POLYNOMIAL(2, 4, -4, 1)) <<  " ( 0 )" << std::endl;
	std::cout << (POLYNOMIAL() % POLYNOMIAL(2, 4, -4, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(1, 1, 2) / POLYNOMIAL(2, 4, -4, 1)) <<  " ( 0 )" << std::endl;
	std::cout << (POLYNOMIAL(1, 1, 2) % POLYNOMIAL(2, 4, -4, 1)) <<  " ( 1, 2 )" << std::endl;

	std::cout << (POLYNOMIAL(3, -1, 4, -5, 2) / POLYNOMIAL(1, -1, 1)) <<  " ( 1, -3, 2 )" << std::endl;
	std::cout << (POLYNOMIAL(3, -1, 4, -5, 2) % POLYNOMIAL(1, -1, 1)) <<  " ( 0 )" << std::endl;

	std::cout << (POLYNOMIAL(3, -4, -4, 1, 1) / POLYNOMIAL(1, 1, 1)) <<  " ( -4, 0, 1 )" << std::endl;
	std::cout << (POLYNOMIAL(3, -4, -4, 1, 1) % POLYNOMIAL(1, 1, 1)) <<  " ( 0 )" << std::endl;
	std::cout << (POLYNOMIAL(3, -4, -4, 1, 1) / POLYNOMIAL(2, -4, 0, 1)) <<  " ( 1, 1 )" << std::endl;
	std::cout << (POLYNOMIAL(3, -4, -4, 1, 1) % POLYNOMIAL(2, -4, 0, 1)) <<  " ( 0 )" << std::endl;

	return 0;
}
