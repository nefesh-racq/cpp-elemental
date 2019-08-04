/**
 plantilla de clases
**/
template <typename T>
class Pila
{
public:
	Pila(int = 10);
	~Pila()
	{
		delete [] pilaPtr; // liberar memoria dinamica
	}

	bool push(const T&);	// mete un elemento en la pila
	bool pop(T &);			// saca un elemento de la pila

	// determina si la pila esta vacia
	bool estaVacia() const
	{
		return cima == -1;
	}

	// determina si la pila esta llena
	bool estaLlena() const
	{
		return cima == tamanio - 1;
	}

private:
	int tamanio;	// nro de elementos para la pila
	int cima;		// ubicacion del elemento superior (-1 es vacio)
	T* pilaPtr;		// apuntador a la representacion interna de la pila
};


/***   ***/
// constructor
template <typename T>
Pila<T>::Pila(int s)
	: tamanio(s > 0 ? s : 10), cima(-1),
	pilaPtr(new T[tamanio])
{
	;
}

// mete elemento en la pila, si tiene exito devuelve true si no false
template <typename T>
bool Pila<T>::push(const T& valor)
{
	if (!estaLlena())
	{
		pilaPtr[++cima] = valor;	// inserta el elemento
		return true;				// retornamos v ya que se metio
	}

	return false;	// no pudo meter el elemento a la pila
}

// retira un elemento de la pila, si tiene exito retorna true
template <typename T>
bool Pila<T>::pop(T& valor)
{
	if (!estaVacia())
	{
		valor = pilaPtr[cima--];	// elimina el elemento
		return true;
	}

	return false;
}

/************************************************************/
#include <iostream>
using std::cout;
using std::endl;

/*
int main()
{
	Pila<double> pilaDouble(5);	// tamaño 5
	double valorDouble = 1.1;

	cout << "Metiendo elementos en la pilaDouble\n";

	// inserta 5 valores doubles
	while (pilaDouble.push(valorDouble))
	{
		cout << valorDouble << " ";
		valorDouble += 1.1;
	}

	cout << "\nLa pila esta llena. No se puede insertar mas " << valorDouble
		<< "\n\nSacando elementos de la pilaDouble\n";

	// retira elementos de la pila
	while (pilaDouble.pop(valorDouble))
		cout << valorDouble << " ";

	cout << "\nLa pila esta vacia. No se puede sacar\n";

	// pila de datos enteros
	Pila<int> pilaInt;	// tamaño predeterminado de 10 elementos
	int valorInt = 1;

	cout << "\nMetiendo elementos a a pilaInt\n";

	// inserta elementos a la pila
	while (pilaInt.push(valorInt))
		cout << valorInt++ << " ";

	cout << "\nLa pila esta llena. No se puede insertar " << valorInt
		<< "\n\nSacando elementos de la pilaInt\n";

	// retira elementos de la pila
	while (pilaInt.pop(valorInt))
		cout << valorInt << " ";

	cout << endl;

	return 0;
}
*/

// Creación de plantillas de función para probar la plantilla de clase Pila< T >
#include <string>
using std::string;

// plantilla de funcion para manipular Pila<T>
template <typename T>
void pruebaPila(
	Pila<T>& laPila,	// referencia a la pila<T>
	T valor,			// valor inicial a insertar
	T incremento,		// incremento pra los valores subsiguientes
	const string nomPila//nombre del objeto pila<T>
	)
{
	cout << "\nMetiendo elementos a " << nomPila << "\n";

	// mete elementos en la pila
	while (laPila.push(valor))
	{
		cout << valor << " ";
		valor += incremento;
	}

	cout << "\nLa pila esta llena. No se puede insertar mas " << valor
		<< "\n\nSacando elementos de " << nomPila << "\n";

	// retira elementos de la pila
	while (laPila.pop(valor))
		cout << valor << " ";

	cout << "\nLa pila esta vacia. No se puede retirar mas\n";
}

int main()
{
	Pila<double> pilaDouble(5);
	Pila<int> pilaInt;

	pruebaPila(pilaDouble, 1.1, 1.1, "pilaDouble");
	pruebaPila(pilaInt, 1, 1, "pilaInt");

	return 0;
}
