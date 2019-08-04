#include <iostream>
using std::ios;
using std::cerr;
using std::endl;

#include <fstream>
using std::fstream;


#include "MyDB.h"
#include "Campo.h"

MyDB::MyDB(string tabla)
{
	_tabla.setNombreTabla(tabla);
	crearTabla();
}
	
MyDB::~MyDB()
{}

// operaciones de la db
bool MyDB::insert(int id, string descripcion, string valor)
{
	_tabla.setFila(id, descripcion, valor);

	if (_tabla.insert())
		return true;

	return false;
}

bool MyDB::select()
{
	//std::cout << "MyDB::select()\n";
	if (_tabla.select())
		return true;

	return false;
}

bool MyDB::select(int id)
{
	if (_tabla.select(id))
		return true;

	return false;
}

bool MyDB::update(int id, string descripcion, string valor)
{
	if (id != 0)
	{	_tabla.Fila.setId(id);

		if (descripcion != "0")
			_tabla.Fila.setDescripcion(descripcion);
		if (valor != "0")
			_tabla.Fila.setValor(valor);

		if (_tabla.update())
			return true;
	}
	
	return false;
}

bool MyDB::deleted(int id)
{
	_tabla.Fila.setId(id);

	if (_tabla.deleted())
		return true;

	return false;
}

// crea la tabla para el manejo de la bae de datos
void MyDB::crearTabla()
{
	fstream tabla(_tabla.getNombreTabla(), ios::in | ios::out | ios::binary);

	if (!tabla)
		cerr << "no se puede crear la tabla " << _tabla.getNombreTabla() << endl;
	else
	{
		Campo fila;
		//std::cout << "se crea la tabla.." << std::endl;

		// crea 100 espacios para el registro del archivo
		for (int i = 0; i < 100; i++)
			tabla.write(reinterpret_cast<const char*>(&fila), sizeof(Campo));
/*
		Campo fila0(10, "pepito", "123.321");
		tabla.seekg((10 -1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&fila0), sizeof(Campo));

		Campo fila1(20, "jose luis", "321.321");
		tabla.seekg((20 - 1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&fila1), sizeof(Campo));

		Campo fila2(55, "lalolanda", "444.524");
		tabla.seekg((55 - 1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&fila2), sizeof(Campo));
*/
	}
}

/*
miembros datos
private:
	Tabla _tabla;
	Campo _fila;

*/