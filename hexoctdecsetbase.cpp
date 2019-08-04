// uso de los manipuladores de flujos hex, oct, dec y setbase
#include <iostream>
using std::cin;
using std::cout;
using std::dec;
using std::hex;
using std::oct;
using std::endl;

#include <iomanip>
using std::setbase;

int main()
{
	int numero;

	cout << "Escriba un numero decimal: ";
	cin >> numero;

	cout << numero << " en hexadecimal es " << hex << numero << endl;
	cout << dec << numero << " en octal es " << oct << numero << endl;
	cout << setbase(10) << numero << " en decimal es " << numero
		<< endl;

	return 0;
}
