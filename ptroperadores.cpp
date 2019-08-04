// operadores & y * de los punteros
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	int a;
	int *aPtr;

	a = 7;
	aPtr = &a;

	cout << "La direccion de a es " << &a
		<< "\nel valor de aPtr es " << aPtr;

	cout << "\nel valor de a es " << a
		<< "\nel valor de *aPtr es " << *aPtr << endl;

	cout << "\n&aPtr = " << &aPtr << endl;

	cout << "\n\nDemostracion que * y & son inversos uno del otro."
		<< "\n&*aPtr = " << &*aPtr
		<< "\n*&aPtr = " << *&aPtr << endl;

	return 0;
}

