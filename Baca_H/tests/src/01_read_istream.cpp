#include <iostream>
#include <cstdarg>

using namespace std;

#include "../POLYNOMIAL.cpp"

int POLYNOMIAL::overloaded = 0;

#include <string>
#include <sstream>

int main() {
	std::stringstream q_s("0 1");
	POLYNOMIAL q;
	q_s >> q;
	std::cout << q << std::endl;

	std::stringstream r_s("3 1 3 3 1");
	POLYNOMIAL r;
	r_s >> r;
	std::cout << r << std::endl;

	std::stringstream s_s("0 -1");
	POLYNOMIAL s;
	s_s >> s;
	std::cout << s << std::endl;

	std::stringstream t_s("2 3 6 9");
	POLYNOMIAL t;
	t_s >> t;
	std::cout << t << std::endl;

	std::stringstream u_s("2 -3 6 -9");
	POLYNOMIAL u;
	u_s >> u;
	std::cout << u << std::endl;

	std::stringstream w_s("4 5 4 3 0 0");
	POLYNOMIAL w;
	w_s >> w;
	std::cout << w << std::endl;

	std::stringstream z_s("4 0 0 0 0 0");
	POLYNOMIAL z;
	z_s >> z;
	std::cout << z << std::endl;

	std::stringstream o_s("4 0 0 0 0 -1");
	POLYNOMIAL o;
	o_s >> o;
	std::cout << o << std::endl;

	return 0;
}
