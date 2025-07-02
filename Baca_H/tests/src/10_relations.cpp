#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	POLYNOMIAL polynomials[8];

	polynomials[0] = POLYNOMIAL(5, 4, 0, -1, 0, 4, 1);
	polynomials[1] = POLYNOMIAL(5, 4, 0, -1, -1, 4, 0);
	polynomials[2] = POLYNOMIAL(5, 4, 0, -1, 0, 0, 0);
	polynomials[3] = POLYNOMIAL(5, 4, 0, -1, 1, 0, 0);
	polynomials[4] = POLYNOMIAL(5, 4, -1, 0, 0, 0, 0);
	polynomials[5] = POLYNOMIAL(5, 4, 0, 0, 0, 0, 0);
	polynomials[6] = POLYNOMIAL(5, 4, 1, 0, 0, 0, 0);
	polynomials[7] = POLYNOMIAL(5, 0, 0, 0, 0, 0, 0);

	std::cout << "i\tj\t==\t!=\t>\t<\t>=\t<=" << std::endl;

	for(unsigned int i = 0; i < 8; i += 1)
		for(unsigned int j = 0; j < 8; j += 1) {
			const POLYNOMIAL& p = polynomials[i];
			const POLYNOMIAL& q = polynomials[j];

			std::cout << i << '\t' << j << '\t' << (p == q) << '\t' << (p != q) << '\t' << (p > q) << '\t' << (p < q) << '\t' << (p >= q) << '\t' << (p <= q) << std::endl;
		}

	return 0;
}
