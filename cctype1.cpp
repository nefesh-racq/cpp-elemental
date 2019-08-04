// ejempo de funciones islower, isupper, tolower y toupper
#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::islower;
using std::isupper;
using std::tolower;
using std::toupper;

int main()
{
	cout << "islower:\n"
		<< (islower('p') ? "p es una" : "p no es una")
		<< " letra minuscula\n"
		<< (islower('P') ? "P es una" : "P no es una")
		<< " letra minuscula\n"
		<< (islower('5') ? "5 es una" : "5 no es una")
		<< " letra minuscula\n"
		<< (islower('!') ? "! es una" : "! no es una")
		<< " letra minuscula\n";

	cout << "\nisupper:\n"
		<< (isupper('D') ? "D es una" : "D no es una")
		<< " letra mayuscula\n"
		<< (isupper('d') ? "d es una" : "d no es una")
		<< " letra mayuscula\n"
		<< (isupper('8') ? "8 es una" : "8 no es una")
		<< " letra mayuscula\n"
		<< (isupper('$') ? "$ es una" : "$ no es una")
		<< " letra mayuscula\n";

	cout << "\nu convertida a mayuscula es "
		<< static_cast<char>(toupper('u'))
		<< "\n7 a mayuscula es "
		<< static_cast<char>(toupper('7'))
		<< "\n$ a mayuscula es "
		<< static_cast<char>(toupper('$'))
		<< "\nL convetida a minuscula es "
		<< static_cast<char>(tolower('L'))
		<< endl;

	return 0;
}
