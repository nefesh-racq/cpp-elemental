// invierte una cadena introducida usando iteradore de string
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;
//using std::const_iterator;	// esto es error

string leer();
void imprimirAlrevez(const string &);

int main()
{
	string cad;

	cad = leer();
	imprimirAlrevez(cad);

	return 0;
}

string leer()
{
	string temp;

	cout << "Ingrese una cadena de text.\n?: ";
	getline(cin, temp);

	return temp;
}

void imprimirAlrevez(const string &cadena)
{
	string::const_iterator itString;

	itString = cadena.end();

	while (itString != cadena.begin())
	{
		cout << *itString;
		itString--;
	}

	cout << *itString << endl;
}