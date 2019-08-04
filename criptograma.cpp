// criptograma simple usando la clase string
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

string mensaje();
void encriptar(string &);
void desencriptar(string &);

int main()
{
	string texto;

	texto = mensaje();
	cout << "\nEl texto original es:\n"
		<< texto << endl;

	encriptar(texto);
	cout << "\nEl texto encriptado es:\n"
		<< texto
		<< endl;

	desencriptar(texto);
	cout << "\ndesencriptando el texto.....\\\n"
		<< "texto desencriptando:\n"
		<< texto
		<< endl;

	return 0;
}

string mensaje()
{
	string cad;

	cout << "Ingrese un texto para que sea encriptado.\n?: ";
	getline(cin, cad);

	return cad;
}

void encriptar(string &cad)
{
	// 26 letras del abecedario español
	//char abc[] = "abcefghijklmnopqrstuvwxyz";
	// usaremos codigo ascii

	int index = 0;
	string temp;

	while (index < cad.length())
	{
		if (cad.compare(index, 1, " ") != 0)
		{
			temp = (char)((int)cad.at(index) + 2);
			cad.replace(index, 1, temp);
		}

		index++;
	}
	//cout << cad << endl;
}

void desencriptar(string &cad)
{
	int index = cad.length() - 1;
	string temp;

	while (index >= 0)
	{
		if (cad.compare(index, 1, " ") != 0)
		{
			temp = (char)((int)cad.at(index) - 2);
			cad.replace(index, 1, temp);
		}

		index--;
	}
}
