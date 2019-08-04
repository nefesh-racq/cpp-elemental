// demostracion de los manipulaores de flujo boolalpha y noboolalpha
#include <iostream>
using std::cout;
using std::boolalpha;
using std::endl;
using std::noboolalpha;

int main()
{
	bool valorBooleano = true;

	// muestra valorBooleano verdadero predeterminado
	cout << "valorBooleano es: " << valorBooleano << endl;

	// muestra valorBooleano despues de usar boolalpha
	cout << "valorBooleano (boolalpha) es "
		<< boolalpha << valorBooleano << endl;

	cout << "cambio de valorBooleano y uso de noboolalphaņ";
	valorBooleano = false;	// cambio de valor
	cout << noboolalpha << endl;

	// muestra noboolalpha predeterminado despues de usar noboolalpha
	cout << "valorBooleano es " << valorBooleano << endl;

	// muestra el valorBooleano despues de usar boolalpha otra vez
	cout << "valorBooleano (boolalpha) es "
		<< boolalpha << valorBooleano << endl;

	return 0;
}