#include "Nodo.h"

class Lista
{
public:
	Lista();
	~Lista();

	void insertarAlInicio(int &);
	void insertarAlFinal(int &);

	void eliminarDelInicio(int &);
	void eliminarDelFinal(int &);

	void imprimir() const;

private:
	Nodo *inicioPtr;
	Nodo *finalPtr;
};