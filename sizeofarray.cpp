// al aplicar el operador sizeof al nombre de un arreglo
// se devuelve el nro de bytes en el arreglo
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::setw;

size_t getSize(double *);
void imprimeSizeDeTipos();

int main()
{
	double arreglo[20];	// 20 valores double
	double arreglo2[2];	// 2 valores double
	int var;

	cout << "El nro de bytes devueltos por sizeof es de 'double array[20]' = "
		<< sizeof(arreglo) << endl;

	cout << "El nro de bytes devueltos por sizeof es de 'double array2[2]' = "
		<< getSize(arreglo2) << endl;

	arreglo[0] = 12;
	arreglo[1] = 2;
	arreglo[2] = 10;
	cout << "El nro de bytes devueltos por sizeof es de "
		<< getSize(arreglo) << endl;

	cout << "El nro de bytes devueltos por sizeof de var es "
		<< sizeof(var) << endl;

	imprimeSizeDeTipos();

	return 0;
}

size_t getSize(double *ptr)
{
	return sizeof(ptr);
}

void imprimeSizeDeTipos()
{
	cout << "\n los tamaños de los tipos de datos son :" << endl
		<< " sizeof(short) : " << sizeof(short) << endl
		<< "   sizeof(int) : " << sizeof(int) << endl
		<< "sizeof(double) : " << sizeof(double) << endl
		<< "sizeof(string) : " << sizeof(string) << endl
		<< " sizeof(float) : " << sizeof(float) << endl
		<< "  sizeof(bool) : " << sizeof(bool) << endl;
}

