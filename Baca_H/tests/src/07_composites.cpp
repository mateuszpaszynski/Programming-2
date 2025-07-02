#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL p(5, -4, -5, -2, 1, -4, 1);
	POLYNOMIAL q(5, -1, 3, 0, 2, -2, 2);
	POLYNOMIAL r(5, 0, 3, 4, 4, 0, 0);

	p *= q-- % r;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p <<= 2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q >>= -1;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r %= p++ += q--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p += q-- *= r;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q += p >>= 3;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r -= p++ %= q;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p *= q <<= 1;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q %= r++ += p;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r >>= 2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p += q <<= -2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q -= p *= r;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += p %= q;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p <<= -4;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q >>= 5;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r *= p++ += q--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p -= q %= r--;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q <<= 3;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p >>= -2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q %= r-- += p;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r += q <<= 2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q >>= -3;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r <<= 1;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p += q + p-- *= r++;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q -= r - q++ += p;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	r *= p >>= 2;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	p <<= 0;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;

	q >>= 0;
	std::cout << p << std::endl;
	std::cout << q << std::endl;
	std::cout << r << std::endl;
	return 0;
}
