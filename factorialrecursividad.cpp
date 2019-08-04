// ejemplo de recursividad (obtener el factorial)
#include <iostream>
using std::cout;
using std::endl;

long factorial(int);	// prototipo de la funcion

int main()
{
	int n = 10;

	cout << factorial(n) << endl;

	return 0;
}

long factorial(int n)
{

	if (n <= 1)
		return 1;
	else
		return factorial(n - 1) * n;
}
