#include <iostream>
using std::cout;
using std::endl;

int cuboPorValor(int);
void cuboPorReferencia(int &);
void cuboPorReferenciaPtr(int *);

int main()
{
	int numero = 3;
	int numero2 = 3;
	int numero3 = 3;

	cout << "El vlaor original de numero es " << numero;

	numero = cuboPorValor(numero);
	cout << "\nEl nuevo valor de numero es " << numero << endl;

	cout << "\ncubo por referencia\n"
		<< "valor de numero2 es " << numero2;

	cuboPorReferencia(numero2);
	
	cout << "\nEl cubo de numero2 es " << numero2 << endl;

	cout << "\ncubo por referencia usando punteros\n"
		<< "valor de numero3 es " << numero3;

	cuboPorReferenciaPtr(&numero3);
	
	cout << "\nEl cubo de numero3 es " << numero3 << endl;
	return 0;
}

int cuboPorValor(int n)
{
	return n * n * n;
}

void cuboPorReferencia(int &n)
{
	n = n * n * n;
}

void cuboPorReferenciaPtr(int *nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}

