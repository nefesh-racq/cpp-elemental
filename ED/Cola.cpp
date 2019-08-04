// ejemplo de Cola PEPS 
// utilizando la clase Lista
template <typename TIPONODO> class Lista;

template <typename TIPONODO>
class NodoLista
{
	friend class Lista<TIPONODO>;	// hace de lista amiga

public:
	NodoLista(const TIPONODO &);	// 
	TIPONODO obtenerDatos() const;	// devuelve los datos en el nodo

private:
	TIPONODO datos;
	NodoLista<TIPONODO> *sgtePtr;	// siguiente nodo en la lista
};

// constructor
template <typename TIPONODO>
NodoLista<TIPONODO>::NodoLista(const TIPONODO &info)
	: datos(info), sgtePtr(0)
{
	;
}

// devuelve una copia de los datos en el nodo
template <typename TIPONODO>
TIPONODO NodoLista<TIPONODO>::obtenerDatos() const
{
	return datos;
}

/***************************/
#include <iostream>
using std::cout;

template <typename TIPONODO>
class Lista
{
public:
	Lista();	// 
	~Lista();	//
	void insertarAlFrente(const TIPONODO &);
	void insertarAlFinal(const TIPONODO &);
	bool eliminarDelFrente(TIPONODO &);
	bool eliminarDelFinal(TIPONODO &);
	bool estaVacia() const;
	void imprimir() const;

private:
	NodoLista<TIPONODO> *primeroPtr;	// inicio lista
	NodoLista<TIPONODO> *ultimoPtr;		// fin lista

	// funcion utilitaria para asignar un nuevo nodo
	NodoLista<TIPONODO> *obtenerNuevoNodo(const TIPONODO &);
};

// constructor
template <typename TIPONODO>
Lista<TIPONODO>::Lista()
	: primeroPtr(0), ultimoPtr(0)
{
	;
}

// destructor
template <typename TIPONODO>
Lista<TIPONODO>::~Lista()
{
	if (!estaVacia())	// verificamos que la lista esta vacia
	{
		cout << "Destruyendo nodos...\n";

		NodoLista<TIPONODO> *actualPtr = primeroPtr;
		NodoLista<TIPONODO> *tempPtr;

		while (actualPtr != 0)	// elimina los nodos restantes
		{
			tempPtr = actualPtr;
			cout << tempPtr->datos << '\n';
			actualPtr = actualPtr->sgtePtr;
			delete tempPtr;
		}
	}

	cout << "se destruyeron todos los nodos\n\n";
}

// inserta un nodo al frente de la lista
template <typename TIPONODO>
void Lista<TIPONODO>::insertarAlFrente(const TIPONODO &valor)
{
	NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);

	if (estaVacia())	// lista vacia
		primeroPtr = ultimoPtr = nuevoPtr;	// solo hay un nodo
	else
	{
		// apunta el nuevo nodo al anterior que era el primero
		nuevoPtr->sgtePtr = primeroPtr;
		primeroPtr = nuevoPtr;	// orienta primeroPtr a nuevoPtr
	}
}

// inserta un nodo al final de la lista
template <typename TIPONODO>
void Lista<TIPONODO>::insertarAlFinal(const TIPONODO &valor)
{
	NodoLista<TIPONODO> *nuevoPtr = obtenerNuevoNodo(valor);

	if (estaVacia())	// lista vacia
		primeroPtr = ultimoPtr = nuevoPtr;
	else
	{
		ultimoPtr->sgtePtr = nuevoPtr;	// actualiza el nodo que era el ultimo
		ultimoPtr = nuevoPtr;			// nuevo ultimo nodo
	}
}

// elimina un nodo de la parte frontal de la lista
template <typename TIPONODO>
bool Lista<TIPONODO>::eliminarDelFrente(TIPONODO &valor)
{
	if (estaVacia())
		return false;	// no se elimino nada por q esta  vacia
	else
	{
		NodoLista<TIPONODO> *tempPtr = primeroPtr;	// contiene tempPtr para eliminarlo luego
		
		if (primeroPtr == ultimoPtr)
			primeroPtr = ultimoPtr = 0;	// no hay nodos despues de elimar
		else
			primeroPtr = primeroPtr->sgtePtr; // apunta al que era el segundo

		valor = tempPtr->datos;	// devuelve los datos que se van a eliminar
		delete tempPtr;	// libera la memoria de tempPtr

		return true;	// nodo eliminado exitosamente
	}
}

// elimina un nodo de la parte final de la lista
template <typename TIPONODO>
bool Lista<TIPONODO>::eliminarDelFinal(TIPONODO &valor)
{
	if (estaVacia())
		return false;
	else
	{
		NodoLista<TIPONODO> *tempPtr = ultimoPtr;

		if (primeroPtr == ultimoPtr)
			primeroPtr = ultimoPtr = 0;
		else
		{
			NodoLista<TIPONODO> *actualPtr = primeroPtr;

			// localiza el penultimo elemento (nodo)
			while (actualPtr->sgtePtr != ultimoPtr)
				actualPtr = actualPtr->sgtePtr;

			ultimoPtr = actualPtr;	// elimina el ultimo nodo
			actualPtr->sgtePtr = 0;	// ahora es el ultimo nodo
		}

		valor = tempPtr->datos;
		delete tempPtr;

		return true;
	}
}

// verificamos si la lista esta vacia
template <typename TIPONODO>
bool Lista<TIPONODO>::estaVacia() const
{
	return primeroPtr == 0;
}

// devuelve el apuntador al nodo recien asignado
template <typename TIPONODO>
NodoLista<TIPONODO> *Lista<TIPONODO>::obtenerNuevoNodo(const TIPONODO &valor)
{
	return new NodoLista<TIPONODO>(valor);
}

// mostramos el contenido de la lista
template <typename TIPONODO>
void Lista<TIPONODO>::imprimir() const
{
	if (estaVacia())
	{
		cout << "La lista esta vacia\n\n";
		return;
	}

	NodoLista<TIPONODO> *actualPtr = primeroPtr;

	while (actualPtr != 0)
	{
		cout << actualPtr->datos << ' ';
		actualPtr = actualPtr->sgtePtr;
	}

	cout << "\n\n";
}

/*******************************************************
*
*********************************************************/
template <typename TIPOCOLA>
class Cola : private Lista<TIPOCOLA>
{
public:
	void enqueue(const TIPOCOLA &dato)
	{
		this->insertarAlFinal(dato);
	}

	bool dequeue(TIPOCOLA &dato)
	{
		return this->eliminarDelFrente(dato);
	}

	bool estaColaVacia() const
	{
		return this->estaVacia();
	}

	void imprimirCola() const
	{
		this->imprimir();
	}
};

/***********/
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Cola<int> colaInt;	// cola de enteros

	cout << "Procesando una cola de valores enteros" << endl;

	// agrega los eneros a colaInt
	for (int i = 0; i < 3; i++)
	{
		colaInt.enqueue(i);
		colaInt.imprimirCola();
	}

	int enteroSacado;

	while (!colaInt.estaColaVacia())
	{
		colaInt.dequeue(enteroSacado);
		cout << enteroSacado << " se saco de la cola" << endl;
		colaInt.imprimirCola();
	}

	Cola<double> colaDouble;
	double valor = 1.1;

	cout << "Procesando una cola de valores double" << endl;

	for (int j = 0; j < 3; j++)
	{
		colaDouble.enqueue(valor);
		valor += 1.1;
		colaDouble.imprimirCola();
	}

	double doubleSacado;

	while (!colaDouble.estaColaVacia())
	{
		colaDouble.dequeue(doubleSacado);
		cout << doubleSacado << " se saco de la cola" << endl;
		colaDouble.imprimirCola();
	}

	return 0;
}
