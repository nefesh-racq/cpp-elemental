// manejador para la base de datos
#ifndef MYDB_H
#define MYDB_H

#include <string>
using std::string;

#include "Tabla.h"
#include "Campo.h"

class MyDB
{
public:
	MyDB(string = "");
	~MyDB();

	// operaciones de la db
	bool insert(int, string, string);
	bool select();
	bool select(int);
	bool update(int, string, string);
	bool deleted(int);

private:
	Tabla _tabla;

	void crearTabla();
};

#endif//MYDB_H
