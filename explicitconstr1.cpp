#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

void imprimirArray(const string &);

int main()
{
	string s("hola");

	imprimirArray(s);
	//imprimirArray(3);
	imprimirArray(string("123"));

	return 0;
}

void imprimirArray(const string &s)
{
	cout << "la longitud de la cadena es " << s.length()
		<< " y la cadena es " << s << endl;
}
