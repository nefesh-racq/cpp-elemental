// las funciones amigas pueden acceder a los miembros privados de una clase
#include <iostream>
using std::cout;
using std::endl;

// definimos la clase
class Cuenta
{
	friend void setX(Cuenta &, int);	// funcion amiga

public:
	Cuenta() : x(0) { ; }	// iniciamos x en cero
	void imprimir() const
	{
		cout << x << endl;
	}

private:
	int x;
};

// la funcion setX puede modificar los datos privados de cuenta
// debido a que setX se declara como amiga de cuenta
void setX(Cuenta &c, int val)
{
	c.x = val;	// se puede acceder a un miembro privado debido a que seX es funcion amiga
}

int main()
{
	Cuenta contador;

	cout << "contador.x despues de crear la instancia: ";
	contador.imprimir();

	setX(contador, 8);	// establecemos un valor para x
	cout << "contador.x despues de la llamada a la funcion friend setX: ";
	contador.imprimir();

	return 0;
}

