// demostracion de los operadores . y -> para acceder a los miembros de una clase
#include <iostream>
using std::cout;
using std::endl;

// definicion de la clase Cuenta
class Cuenta
{
public:	// datos publicos, peligrosos
	void setX(int valor)
	{
		x = valor;
	}

	void imprimir()
	{
		cout << x << endl;
	}

private:
	int x;
};

int main()
{
	Cuenta contador;	// crea un objeto contador de tipo Cuenta
	Cuenta *contadorPtr = &contador;	// crea un puntero de tipo contador y apunta al objeto contador
	Cuenta &contadorRef = contador;		// crea una referencia de tipo contador y apunta al objeto contador

	cout << "\nEstablece x en 1 e imprimir usando el nombre del objeto\n"
		<< "contador.setX(1) - contador.imprimir().\n";
	contador.setX(1);
	contador.imprimir();

	cout << "\nEStablece x en 2 e imprimir usando referencia a un objeto\n"
		<< "contadorRef.setX(2)  -  contadorRef.imprimir().\n";
	contadorRef.setX(2);
	contadorRef.imprimir();

	cout << "\nEstablece x en 3 e imprimir usando el puntero\n"
		<< "contadorPtr->setX(3)  -  contadorPtr->imprimir().\n";
	contadorPtr->setX(3);
	contadorPtr->imprimir();

	cout << "\nEstablecer x en 4 e imprimir usando el puntero desreferenciado.\n"
		<< "(*contadorPtr).setX()  - (*contadorPtr).imprimir().\n";
	(*contadorPtr).setX(4);
	(*contadorPtr).imprimir();

	return 0;
}

