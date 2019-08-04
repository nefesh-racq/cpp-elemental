#include <cstring>
using std::strcpy;

#include "Campo.h"

// tiene parametros por defecto
Campo::Campo(int id, string descripcion, string valor)
{
	setId(id);
	setDescripcion(descripcion);
	setValor(valor);
}
	
Campo::~Campo()
{}

// get
int Campo::getId() const
{
	return _id;
}

string Campo::getDescripcion() const
{
	return _descripcion;
}

string Campo::getValor() const
{
	return _valor;
}

/*
	no se hacen las validaciones para los datos
*/

// set
void Campo::setId(int id)
{
	_id = id;
}

void Campo::setDescripcion(string descripcion)
{
	strcpy(_descripcion, descripcion.data());
	_descripcion[descripcion.length()] = '\0';
}

void Campo::setValor(string valor)
{
	strcpy(_valor, valor.data());
	_valor[valor.length()] = '\0';
}

/*
miembros datos
private:
	int _id;
	string _descripcion;
	string _valor;

*/