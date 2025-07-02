#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL p(4, 1, 2, 3, 4, 5);
	POLYNOMIAL q(2, 3, 9, 6);
	POLYNOMIAL r(1, 1, 0);

	POLYNOMIAL t;

	t = p;
	std::cout << t << std::endl;

	t = t;
	std::cout << t << std::endl;

	t = q;
	std::cout << t << std::endl;

	t = r;
	std::cout << t << std::endl;

	t = q = r = p = q;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;
	std::cout << t << std::endl;

	return 0;
}
