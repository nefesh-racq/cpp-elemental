// impresion de un entero con espaciamiento interno y
// un signo positivo
#include <iostream>
using std::cout;
using std::endl;
using std::internal;
using std::showpos;

#include <iomanip>
using std::setw;

int main()
{
	// muestra el valor con espaciamiento interno y signo positivo
	cout << internal << showpos << setw(10) << 123 << endl;

	return 0;
}