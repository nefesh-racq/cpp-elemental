// demostracion de isspace, iscntrl, ispunct, isprint, isgrarph
#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::iscntrl;
using std::isgraph;
using std::ispunct;
using std::isspace;

int main()
{
	cout << "isspace:\n nueva linea "
		<< (isspace('\n') ? "es un" : "no es un")
		<< " caracter de espacio en blanco\nTabulador horizontal "
		<< (isspace('\t') ? "es un" : "no es un")
		<< " caracter de espacio en blanco\n"
		<< (isspace('%') ? "% es un" : "% no es un")
		<< " carcter de espacio en blanco\n";

	cout << "\niscntrl:\nnueva linea "
		<< (iscntrl('\n') ? "es un" : "no es un")
		<< " caracter de control\n"
		<< (iscntrl('$') ? "$ es un" : "$ no es un")
		<< " caracter de control\n";

	cout << "\nispunct:\n"
		<< (ispunct(';') ? "; es un" : "; no es un")
		<< " caracter de puntuacion\n"
		<< (ispunct('Y') ? "Y es un" : "Y no es un")
		<< " caracter de puntuacion\n"
		<< (ispunct('#') ? "# es un" : "# no es un")
		<< " caracter de puntuacion\n";

	cout << "\nisprint:\n"
		<< (isprint('$') ? "$ es un" : "$ no es un")
		<< " caracter de impresion\nAlert "
		<< (isprint('\a') ? "es un" : "no es un")
		<< " caracter de impresion\nespacio "
		<< (isprint(' ') ? "es un" : "no es un")
		<< " caracter de impresion\n";

	cout << "\nisgraph:\n"
		<< (isgraph('Q') ? "Q es un" : "Q no es un")
		<< " caracter de impresion distinto de un espacio\nspace "
		<< (isgraph(' ') ? "es un" : "no es un")
		<< " caracter de impresion distinto de un espacio\n";

	return 0;
}