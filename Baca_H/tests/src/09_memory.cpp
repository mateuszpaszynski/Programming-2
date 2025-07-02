#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

int main() {
	std::cout << POLYNOMIAL::overloaded << std::endl;

	POLYNOMIAL* p = new POLYNOMIAL();

	std::cout << POLYNOMIAL::overloaded << std::endl;

	POLYNOMIAL* q = new POLYNOMIAL();
	POLYNOMIAL* r = new POLYNOMIAL();
	POLYNOMIAL* s = new POLYNOMIAL();

	std::cout << POLYNOMIAL::overloaded << std::endl;

	delete p;
	p = NULL;
	delete r;
	r = NULL;
	//explicit null deletion which is safe
	delete r;
	delete r;

	std::cout << POLYNOMIAL::overloaded << std::endl;

	POLYNOMIAL* polynomials = new POLYNOMIAL[10];

	std::cout << POLYNOMIAL::overloaded << std::endl;

	POLYNOMIAL a, b, c, d, e, f, g, h;

	std::cout << POLYNOMIAL::overloaded << std::endl;

	delete[] polynomials;
	polynomials = NULL;

	std::cout << POLYNOMIAL::overloaded << std::endl;

	delete q;
	q = NULL;

	std::cout << POLYNOMIAL::overloaded << std::endl;

	POLYNOMIAL stack_array[4];

	std::cout << POLYNOMIAL::overloaded << std::endl;

	delete s;
	s = NULL;
	//explicit null deletion which is safe
	delete s;
	delete s;
	delete s;
	delete s;


	std::cout << POLYNOMIAL::overloaded << std::endl;

	return 0;
}
