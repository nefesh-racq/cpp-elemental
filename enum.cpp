#include <iostream>

using namespace std;

int main() {
	enum CHAR {A = 100, B, C, D, E};

	CHAR caracter;

	caracter = B;

	cout << caracter << endl;

	return 0;
}
