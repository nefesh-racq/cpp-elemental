// uso del apuntado this pra hacer referencia a los miembros de un objeto
#include <iostream>
using std::cout;
using std::endl;

class Prueba
{
public:
	Prueba(int = 0);	// constr. con parametros predeterminados
	void imprimir() const;

private:
	int x;
};

// constr.
Prueba::Prueba(int valor) : x(valor)
{ ; }

// imprimimos x usando el apuntador implicito y explicito
// los parentesis alrededor de *this son obligados
void Prueba::imprimir() const
{
	// apuntador implicito "this" para acceder al miembro x
	cout << "        x = " << x;

	// apuntador "this" explicito se debe usar el operador fecha
	// para acceder a la x
	cout << "\n  this->x = " << this->x;

	// usa de manera explicita el apuntador this desreferenciado, mas
	// el operador punto para acceder a la x
	cout << "\n(*this).x = " << (*this).x << endl;
}

int main()
{
	Prueba objetoPrueba(12);	// objeto objetoPrueba

	objetoPrueba.imprimir();

	return 0;
}

