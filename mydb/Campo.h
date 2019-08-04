// clase para los campos de la tabla
#ifndef CAMPO_H
#define CAMPO_H

#include <string>
using std::string;

class Campo
{
public:
	Campo(int = 0, string = "", string = "");
	~Campo();

	// get
	int getId() const;
	string getDescripcion() const;
	string getValor() const;

	// set
	void setId(int);
	void setDescripcion(string);
	void setValor(string);

private:
	int _id;
	char _descripcion[30];
	char _valor[8];
};

#endif//CAMPO_H