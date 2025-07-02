#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL polynomials[6];

	polynomials[0] = POLYNOMIAL(5, 4, 0, -1, 0, 4, 1);
	polynomials[1] = POLYNOMIAL(5, -1, 0, 1, 2, -4, 3);
	polynomials[2] = POLYNOMIAL(5, -5, -5, 1, -1, 4, 2);
	polynomials[3] = POLYNOMIAL(5, -3, -1, 3, 4, 4, 3);
	polynomials[4] = POLYNOMIAL(5, 4, -1, -1, 5, -1, 2);
	polynomials[5] = POLYNOMIAL(5, 1, 1, -3, 2, 2, 1);


	std::cout << "BASE:" << std::endl;
	for(unsigned int i = 0; i < 6; i += 1)
		std::cout << 'p' << i << " = " << polynomials[i] << std::endl;

	std::cout << "NEGATIVES:" << std::endl;
	for(unsigned int i = 0; i < 6; i += 1)
		std::cout << "-p" << i << " = " << -polynomials[i] << std::endl;


	std::cout << "ADDITION:" << std::endl;
	for(unsigned int i = 0; i < 6; i += 1)
		for(unsigned int j = 0; j < 6; j += 1)
			std::cout << 'p' << i << " + p" << j << " = " << polynomials[i] + polynomials[j] << std::endl;

	std::cout << "SUBSTRACTION:" << std::endl;
	for(unsigned int i = 0; i < 6; i += 1)
		for(unsigned int j = 0; j < 6; j += 1)
			std::cout << 'p' << i << " - p" << j << " = " << polynomials[i] - polynomials[j] << std::endl;


	std::cout << "EDGE CASES:" << std::endl;
	std::cout << POLYNOMIAL(3, 1, 3, 3, 1) + POLYNOMIAL(3, -1, -3, -3, -1) << std::endl;
	std::cout << POLYNOMIAL(3, 1, 3, 3, 1) + POLYNOMIAL(3, 0, -2, -3, -1) << std::endl;
	return 0;
}
