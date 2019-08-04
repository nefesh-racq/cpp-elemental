class Implementacion
{
public:
	Implementacion(int, const char*);
	~Implementacion();

	void setValor(int);
	void setNombre(const char*);
	int getValor() const;
	void printValor() const;

private:
	int valor;
	const char *nombre;
};

///
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;
using std::strcpy;

Implementacion::Implementacion(int v, const char *c)
	: valor(v), nombre(c)
{ ; }

Implementacion::~Implementacion()
{
	
}

void Implementacion::setValor(int v)
{
	valor = v;
}

void Implementacion::setNombre(const char *nom)
{
	nombre = nom;	// no se si sea buena idea
}

int Implementacion::getValor() const
{
	return valor;
}

void Implementacion::printValor() const
{
	cout << "valor de " << nombre << " es : " << valor << endl;
}

/****************************************************/
class Manejador
{
public:
	Manejador(int, const char*);
	~Manejador();

	void setValor(int);
	void setNombre(const char *);
	int getValor() const;
	void printValor() const;

private:
	Implementacion *ptr;
};

Manejador::Manejador(int v, const char *nom)
	: ptr(new Implementacion(v, nom))
{ ; }

Manejador::~Manejador()
{
	delete ptr;
	ptr = 0;
}

void Manejador::setValor(int v)
{
	ptr->setValor(v);
}

void Manejador::setNombre(const char *nom)
{
	ptr->setNombre(nom);
}

int Manejador::getValor() const
{
	return ptr->getValor();
}

void Manejador::printValor() const
{
	ptr->printValor();
}

/********************************************************/

int main()
{
	Manejador obj(55, "pepe");

	cout << "obj print : \n";
	obj.printValor();

	obj.setValor(15);
	obj.setNombre("jose jose");
	cout << "obj despues de set valor\n";
	obj.printValor();

	return 0;
}

