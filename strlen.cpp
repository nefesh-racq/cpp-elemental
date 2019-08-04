// uso de strlen
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;

int main()
{
	const char *cad1 = "abcdefghijklmnopqrstuvwxyz";
	const char *cad2 = "cuatro";
	const char *cad3 = "new york";

	cout << "La longitud de \"" << cad1 << "\" es " << strlen(cad1)
		<< "\nLa longitud de \"" << cad2 << "\" es " << strlen(cad2)
		<< "\nLa longitud de \"" << cad3 << "\" es " << strlen(cad3)
		<< endl;

	return 0;
}

