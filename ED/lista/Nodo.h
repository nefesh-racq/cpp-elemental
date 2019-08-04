// clase Nodo, como plantilla para fomentar la reutilizacion
// de codigo,

#ifndef NODO_H
#define NODO_H

// declaramos la clase anticipadamente para opder definirla
// como friend de la clase nodo, asi poder acceder a sus datos
// private desde Lista
template <typename TIPOLISTA>
class Lista;

template <typename TIPONODO>
class Nodo
{
	// declaramos la clase Lista como funcion amiga
	friend class Lista<TIPONODO>;

public:
	Nodo();
	Nodo(TIPONODO &);
	~Nodo();

	//TIPONODO getInfo() const;

private:
	TIPONODO info;				// se puede acceder desde class Lista
	Nodo<TIPONODO> *sgtePtr;	// se puede acceder desde class Lista
};

#endif//NODO_H