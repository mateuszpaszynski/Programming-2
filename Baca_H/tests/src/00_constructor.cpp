#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL p;
	std::cout << p << std::endl;

	POLYNOMIAL q(0, 1);
	std::cout << q << std::endl;

	POLYNOMIAL r(3, 1, 3, 3, 1);
	std::cout << r << std::endl;

	POLYNOMIAL s(0, -1);
	std::cout << s << std::endl;

	POLYNOMIAL t(2, 3, 6, 9);
	std::cout << t << std::endl;

	POLYNOMIAL u(2, -3, 6, -9);
	std::cout << u << std::endl;

	POLYNOMIAL w(4, 5, 4, 3, 0, 0);
	std::cout << w << std::endl;

	POLYNOMIAL z(4, 0, 0, 0, 0, 0);
	std::cout << z << std::endl;

	POLYNOMIAL o(4, 0, 0, 0, 0, -1);
	std::cout << o << std::endl;

	return 0;
}
