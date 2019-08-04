#include <iostream>
#define SUM(a, b) (a + b)
#define VERIFICAR

using namespace std;

int main() {
	int a, b;

	a = 5;
	b = 2;

	cout << "sum : " << (a+ b) << endl;

	// con esto quitamos la definicion de VERIFICAR
	#undef VERIFICAR

	#ifdef VERIFICAR
		cout << "definido" << endl;
	#else
		cout << "no definido" << endl;
	#endif

	return 0;
}