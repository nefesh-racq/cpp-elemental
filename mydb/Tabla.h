// tabla 
#ifndef TABLA_H
#define TABLA_H

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include "Campo.h"

class Tabla
{
public:
	Campo Fila;

	Tabla(string = "");
	Tabla(string, Campo &);
	~Tabla();

	// get
	string getNombreTabla() const;
	Campo getFila() const;

	// set
	void setNombreTabla(string);
	void setFila(Campo &);
	void setFila(int, string, string);

	// operaciones de la db
	bool insert();
	bool select();
	bool select(int);
	bool update();
	bool deleted();

private:
	string _nombre;
	fstream _tabla;

	void imprimirLinea(const Campo &) const;
};

#endif//TABLA_H
