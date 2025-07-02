#include "../include/headers.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string compute_result(int count, string numbers[]) {
	return Mult(count, numbers);
}

string remove_plus(string s) {
	if(s.length() != 0 && s[0] == '+')
		s.erase(0, 1);
	return s;
}

int main(int argc, char** argv) {
	if(argc != 3)
		return -1;

	string test_name = argv[1];
	string file_name = argv[2];

	string input_file = file_name + ".in";
	string output_file = file_name + ".out";

	fstream input(input_file, ios::in);
	fstream output(output_file, ios::in);

	int count;
	input >> count;

	string* numbers = new string[count];
	for(unsigned short i = 0; i < count; i = i + 1)
		input >> numbers[i];

	string correct_output;
	output >> correct_output;

	string result = remove_plus(compute_result(count, numbers));

	bool is_result_correct = result == correct_output;

	delete[] numbers;

	if(!is_result_correct) {
		cerr << "[\033[33mDEBUG\033[0m] FAILED TEST " << test_name << '\n';
		cerr << "[\033[33mDEBUG\033[0m] EXPECTED OUTPUT: >" << correct_output << "<\n";
		cerr << "[\033[33mDEBUG\033[0m] YOUR OUTPUT:     >" << result << "<\n";
		cerr << "[\033[33mDEBUG\033[0m] > AND < SYMBOLS ARE ADDED TO SEE WHITESPACE\n";
		cout << "[\033[31mANS\033[0m] ! " << test_name << '\n';
		return 1;
	}

	cout << "[\033[32mOK\033[0m]    " << test_name << '\n';
	return 0;
}
