#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Ejemplo
{
private:
	int datos;
	string nombre;

public:
	static int cuenta;

	Ejemplo();
	Ejemplo(string);
	Ejemplo(string, int);
	Ejemplo(const Ejemplo &);
	~Ejemplo();
};


// definicion de la clase Ejemplo
int Ejemplo::cuenta = 0;

Ejemplo::Ejemplo()
{
	nombre = "None";
	datos = 0;
	cuenta++;		// nuevo objeto creado


	cout << "...creando objeto " << nombre << endl;
}

Ejemplo::Ejemplo(string nom)
{
	nombre = nom;
	datos = 0;
	cuenta++;		// nuevo objeto creado

	cout << "...creando objeto " << nombre << endl;
}

Ejemplo::Ejemplo(string nom, int g)
{
	nombre = nom;
	datos = g;
	cuenta++;		// nuevo objeto creado

	cout << "...creando objeto " << nombre << endl;
}

Ejemplo::Ejemplo(const Ejemplo &origen)
{
	datos = origen.datos;
	cuenta++;		// nuevo objeto creado

	cout << "...creando objeto (copia) " << nombre << endl;
}

Ejemplo::~Ejemplo()
{
	cuenta--;

	cout << "...destruyendo objeto " << nombre << endl;
}

/*************************************************************/

int main()
{
	Ejemplo d1("d1"), d2("d2");

	cout << "Nro Objetos: " << Ejemplo::cuenta << "\n\n";

	if (true)
	{
		Ejemplo d3("d3", 88);
		cout << "Nro Ojbetos: " << Ejemplo::cuenta << "\n\n";
	}

	cout << "Nro Ojbetos: " << Ejemplo::cuenta << "\n\n";
	Ejemplo* ptr;

	ptr = new Ejemplo("ptr");

	cout << "Nro Ojbetos: " << Ejemplo::cuenta << "\n\n";

	delete ptr;

	cout << "Nro Ojbetos: " << Ejemplo::cuenta << "\n\n";

	return 0;
}
