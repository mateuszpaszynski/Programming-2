#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

#include <sstream>

//prompt: based on these overloaded operators generate a lot of weird and quorky test to test all of them. don't limit yourself and unleash the wildest tests

int main() {
	// 💡 Constructors
	POLYNOMIAL a;                        // default
	POLYNOMIAL b(2, 1, -1, 3);           // degree 2: x^2 - x + 3
	POLYNOMIAL c(b);                     // copy constructor
	POLYNOMIAL d(4, 0, 0, 0, 0, 1);      // x^4

	std::cout << "Constructors:\n" << a << std::endl << b << std::endl << c << std::endl << d << std::endl;

	// 🌀 Unary madness
	POLYNOMIAL neg = -(-(-b));
	std::cout << "Triple negation:\n" << neg << std::endl;

	// 🎲 Arithmetic stew
	POLYNOMIAL stew = ((a + b) * (c - d)) / (c + d % b);
	std::cout << "Arithmetic stew:\n" << stew << std::endl;

	// 🪄 Compound ops dance
	a += b *= c -= d %= (neg + (stew << 1));
	std::cout << "Compound operators:\n" << a << std::endl << b << std::endl << c << std::endl << d << std::endl;

	// ⏩ Shift me baby one more time
	POLYNOMIAL shift_party = ((a << 3) >> -2) << 0;
	std::cout << "Shift party:\n" << shift_party << std::endl;

	// 🔄 Chained shift assignments
	shift_party <<= 2;
	std::cout << "Shift chain:\n" << shift_party << std::endl;

	// 🎢 Pre/Post inc/dec combo
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "Final a: " << a << std::endl;

	// 👯 Comparisons from chaos
	if (a == b) std::cout << "a == b\n";
	if (a != c) std::cout << "a != c\n";
	if (a < d) std::cout << "a < d\n";
	if (a <= d) std::cout << "a <= d\n";
	if (a > b) std::cout << "a > b\n";
	if (a >= b) std::cout << "a >= b\n";

	// 🎭 I/O simulation
	std::stringstream ss("3 2 0 -1 5");  // degree 3: 2x^3 - x + 5
	POLYNOMIAL io;
	ss >> io;
	std::cout << "Input polynomial from stringstream:\n" << io << std::endl;

	// 🧨 Self-assignment? Sure
	io = io;
	std::cout << "Self-assigned:\n" << io << std::endl;

	// 🎉 Allocate and destroy manually
	POLYNOMIAL* dyn = new POLYNOMIAL(1, 5, -2); // 5x - 2
	std::cout << "Dynamically allocated:\n" << *dyn << std::endl;
	delete dyn;

	// 💫 Recursive nonsense
	POLYNOMIAL w(0, 1); // constant 1
	for (int i = 0; i < 3; ++i) {
		w = (w * w + w) >> 1;
		std::cout << "Recursive w step " << i << ":\n" << w << std::endl;
	}

	// 🪤 Test of doom
	POLYNOMIAL doom = (((((a + b) - (c * d)) << 2) % (neg + neg)) >>= -3) + ++a;
	std::cout << "Test of doom:\n" << doom << std::endl;

	// 🔁 Assignment
	a = b = c = d;
	std::cout << "Assignment Chain:\n" << a << std::endl << b << std::endl << c << std::endl << d << std::endl;

	return 0;
}
