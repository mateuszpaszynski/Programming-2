#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL p(4, 1, 3, 5, 7, -1);

	std::cout << p << std::endl;

	POLYNOMIAL q = ++p;

	std::cout << p << std::endl;
	std::cout << q << std::endl;

	POLYNOMIAL r = q;
	r += p++ + ++q;

	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r -= ++q + p++ + --p - q--;

	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << "R: " << r << std::endl;

	r -= p++ += q-- += q -= ++p--;

	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p += ++q;

	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	std::cout << p << std::endl;
	std::cout << ++p << std::endl;
	std::cout << p++ << std::endl;
	std::cout << p << std::endl;

	std::cout << q << std::endl;
	std::cout << ++q << std::endl;
	std::cout << q++ << std::endl;
	std::cout << q << std::endl;

	std::cout << r << std::endl;
	std::cout << ++r << std::endl;
	std::cout << r++ << std::endl;
	std::cout << r << std::endl;

	std::cout << p << std::endl;
	std::cout << --p << std::endl;
	std::cout << p-- << std::endl;
	std::cout << p << std::endl;

	std::cout << q << std::endl;
	std::cout << --q << std::endl;
	std::cout << q-- << std::endl;
	std::cout << q << std::endl;

	std::cout << r << std::endl;
	std::cout << --r << std::endl;
	std::cout << r-- << std::endl;
	std::cout << r << std::endl;

	r -= p++ += q-- += q -= ++p--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += --p += ++q -= q-- += p++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r = p-- += q++ -= r += --q++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += p++ -= q++ += r-- += ++p--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r -= q++ += --p -= r += q--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r = ++p -= --q += q++ -= --r++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += p-- += q-- += r++ -= p++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r = r++ += q += p-- -= --q += ++p;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += --q += ++p -= p-- += q++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r = p++ += q-- -= r-- += ++p;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	return 0;
}
