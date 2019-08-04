class Implementacion
{
public:
	Implementacion(int v)
		: valor(v)
	{ ; }

	void setValor(int v)
	{
		valor = v;
	}

	int getValor() const
	{
		return valor;
	}

private:
	int valor;
};

/*********************************************************/
// definicion de la clase proxy Interfaz

class Implementacion;	// declaracion anticipada de la clase

class Interfaz
{
public:
	Interfaz(int);
	void setValor(int);
	int getValor() const;
	~Interfaz();

private:
	Implementacion *ptr;
};

/**********************************************************/
Interfaz::Interfaz(int v)
	: ptr(new Implementacion(v))
{ ; }

// llama a la funcion setValor de Implementacion
void Interfaz::setValor(int v)
{
	ptr->setValor(v);
}

// llama a la funcion getValor de Implementacion
int Interfaz::getValor() const
{
	return ptr->getValor();
}

// destructor
Interfaz::~Interfaz()
{
	delete ptr;
}

/**********************************************************/
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Interfaz i(5);	// instacia un objeto Interfaz

	cout << "Interfaz contiene: " << i.getValor()
		<< " antes de setValor" << endl;

	i.setValor(10);

	cout << "Interfaz contiene: " << i.getValor()
		<< " despues de setValor" << endl;

	return 0;
}
