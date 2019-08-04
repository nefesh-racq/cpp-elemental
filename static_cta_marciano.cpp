// ejemplo miembro dato static
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


class Marciano
{
public:
	Marciano(int);
	void imprimirEstado() const;
	int getCantMarcianos() const;

private:
	int nombre;
	static int cantMarciano;
	
	// funciones
	void incMarciano();
};

// inicializacion de el miembro statico de la clase
int Marciano::cantMarciano = 0;

Marciano::Marciano(int nom)	: nombre(nom)
{
	incMarciano();
}

void Marciano::imprimirEstado() const
{
	if (cantMarciano > 5)
		cout << "\nmarciano " << nombre << " es hostil\n";
	else
		cout << "\nmarciano " << nombre << " es amistoso\n";
}

int Marciano::getCantMarcianos() const
{
	return cantMarciano;
}

void Marciano::incMarciano()
{
	cantMarciano++;
}

int main()
{
	Marciano a(1);

	a.imprimirEstado();
	cout << "cant : " << a.getCantMarcianos();

	Marciano b(2);

	b.imprimirEstado();
	cout << "cant : " << b.getCantMarcianos();

	Marciano c(3);

	c.imprimirEstado();
	cout << "cant : " << c.getCantMarcianos();

	cout << endl;

	return 0;
}
