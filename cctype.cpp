// demostracion de las funciones isdigit, isalpha, isalnum, isxdigit
#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::isalnum;
using std::isalpha;
using std::isdigit;
using std::isxdigit;

int main()
{
	cout << "isdigit:\n"
		<< (isdigit('8') ? "8 es un" : "8 no es un") << " digito\n"
		<< (isdigit('#') ? "# es un" : "# no es un") << " digito\n"
		<< endl;

	cout << "\nisalpha:\n"
		<< (isalpha('A') ? "A es una" : "A no es una") << " letra\n"
		<< (isalpha('b') ? "b es una" : "b no es una") << " letra\n"
		<< (isalpha('&') ? "& es una" : "& no es una") << " letra\n"
		<< (isalpha('4') ? "4 es una" : "4 no es una") << " letra\n"
		<< endl;

	cout << "\nisalnum:\n"
		<< (isalnum('A') ? "A es un" : "A no es un") << " digito/letra\n"
		<< (isalnum('8') ? "8 es un" : "8 no es un") << " digito/letra\n"
		<< (isalnum('#') ? "# es un" : "# no es un") << " digito/letra\n"
		<< endl;

	cout << "\nisxdigit:\n"
		<< (isxdigit('F') ? "F es un" : "F no es un") << " digito hex\n"
		<< (isxdigit('J') ? "J es un" : "J no es un") << " digito hex\n"
		<< (isxdigit('7') ? "7 es un" : "7 no es un") << " digito hex\n"
		<< (isxdigit('f') ? "f es un" : "f no es un") << " digito hex\n"
		<< endl;

	return 0;
}
