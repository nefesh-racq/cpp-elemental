#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

/** declaracion **/

const int M = 20;

class Conjunto
{
private:
	string* cto;
	int cardinal;
	int capacidad;

public:
	Conjunto();
	Conjunto(const Conjunto &);
	bool esVacio() const;
	void annadir(string);
	void retirar(string);
	bool pertenece(string) const;
	int cardinall() const;
	Conjunto unionn(const Conjunto&);
	void print() const;
};

/** definicion **/

Conjunto::Conjunto()
{
	cto = new string[M];
	cardinal = 0;
	capacidad = M;
}

Conjunto::Conjunto(const Conjunto& origen)
{
	cardinal = origen.cardinal;
	capacidad = origen.capacidad;
	cto = new string[capacidad];	// copia segura por usar puntero memoria dinamica

	for (int i = 0; i < cardinal; i++)
		cto[i] = origen.cto[i];
}

bool Conjunto::esVacio() const
{
	return (cardinal == 0);
}

void Conjunto::annadir(string elemento)
{
	if (!pertenece(elemento))
	{
		// amplia el conjunto si no hay posiciones disponibles
		if (cardinal == capacidad)
		{
			string* nuevoCto = new string[capacidad + M];

			for (int i = 0; i < cardinal; i++)
				nuevoCto[i] = cto[i];

			delete cto;
			cto = nuevoCto;
			capacidad += M;
		}

		cto[cardinal++] = elemento;
	}
}

void Conjunto::retirar(string elemento)
{
	if (pertenece(elemento))
	{
		int k = 0;

		while (!(cto[k] == elemento)) k++;

		// mueve a la izquierda desde elemento k+1 hasta la ultima posicion
		for (; k < cardinal; k++)
			cto[k] = cto[k + 1];

		cardinal--;
	}
}

bool Conjunto::pertenece(string elemento) const
{
	int k = 0;
	bool encontrado = false;

	while (k < cardinal && !encontrado)
	{
		encontrado = (cto[k] == elemento);
		k++;
	}
}

int Conjunto::cardinall() const
{
	return this->cardinal;
}

Conjunto Conjunto::unionn(const Conjunto& c2)
{
	int k;
	Conjunto u;	// conjunto union

	// priemro copia el primer operando de la union
	for (k = 0; k < cardinal; k++)
		u.cto[k] = cto[k];

	u.cardinal = cardinal;

	// añade los elelemtos de c2 no incluidos
	for (k = 0; k < c2.cardinal; k++)
		u.annadir(c2.cto[k]);

	return u;
}

void Conjunto::print() const
{
	cout << *cto << endl;
}

/***************************************************************/
int main()
{
	Conjunto a1;
	Conjunto a2;
	Conjunto a3;

	a1.annadir("abcde");
	a1.print();


	a2.annadir("fghijkl");
	a2.print();

	a3 = a1.unionn(a2);
	a3.print();

	a1.annadir("o");
	a1.print();

	return 0;
}
