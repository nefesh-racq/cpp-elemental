// nodo arbol
#ifndef NODOARBOL_H
#define NODOARBOL_H

// declaracion clase Arbol
template <typename TIPONODO>
class Arbol;

// plantilla NodoArbol
template <typename TIPONODO>
class NodoArbol
{
	friend class Arbol<TIPONODO>;

public:
	NodoArbol(const TIPONODO &d)
		: izquierdoPtr(0),	// apuntador subarbol izquierdo
		  datos(d),			// datos del nodo arbol
		  derechoPtr(0)		// apuntador subarbol derecho
	{}

	//
	TIPONODO obtenerDatos() const
	{
		return datos;
	}

private:
	NodoArbol<TIPONODO> *izquierdoPtr;
	TIPONODO datos;
	NodoArbol<TIPONODO> *derechoPtr;
};

#endif//NODOARBOL_H