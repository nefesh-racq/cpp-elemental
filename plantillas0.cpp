/*
 ejemplo de plantillas en c++
 se debe usar el operador class o typename dentro de <>
*/
#include <iostream>
using std::cout;
using std::endl;

template <class T>
T sumar(T a, T b)
{
	return a + b;
}

template <typename data>
data mult(data a, data b)
{
	return a * b;
}

int main()
{
	int a = 10;
	int b = 33;

	cout << sumar(a, b) << endl;
	cout << mult(a, b) << endl;

	float c = 3.4;
	float d = 2.5;

	cout << sumar(c, d) << endl;
	cout << mult(c, d) << endl;

	return 0;
}