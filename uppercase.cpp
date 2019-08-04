// el manipulador de flujo uppercase
#include <iostream>
using std::cout;
using std::endl;
using std::hex;
using std::showbase;
using std::uppercase;

int main()
{
	cout << "Impresion letras mayusculas en exponentes de\n"
		<< "notacion cientifica y valores hexadecimales.\n";

	// usa std::upercase para mosrar letras mayusculas
	// usa std::hex y std::showbase para mostrar un valor
	// hexadecimal y su base
	cout << uppercase << 4.345e10 << endl
		<< hex << showbase << 123456789 << endl;

	return 0;
}
