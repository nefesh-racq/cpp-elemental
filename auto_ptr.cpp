// demostracion de auto_ptr 
class Entero
{
public:
	Entero(int i = 0);
	~Entero();	//

	void setEntero(int i);
	int getEntero() const;

private:
	int valor;
};

#include <iostream>
using std::cout;
using std::endl;

Entero::Entero(int i)
	: valor(i)
{
	cout << "Constructor para entero " << valor << endl;
}

Entero::~Entero()
{
	cout << "Destructor para entero " << valor << endl;
}


void Entero::setEntero(int i)
{
	valor = i;
}

int Entero::getEntero() const
{
	return valor;
}

#include <memory>
using std::auto_ptr;	// definicion de la clase auto_ptr

int main()
{
	cout << "Creacion de un objeto auto_ptr que apunta a un objeto entero\n";

	// orienta auto_ptr a un objeto entero
	auto_ptr<Entero> ptrAEntero(new Entero(7));

	cout << "\nUso de auto_ptr para manipular un entero\n";
	ptrAEntero->setEntero(99);	// usa auto_ptr para setEntero

	// usa auto_ptr para obtener el valor de entero
	// se usa el puntero desreferenciado
	cout << "Entero despues de setEntero: " << (*ptrAEntero).getEntero() << endl;

	return 0;
}
