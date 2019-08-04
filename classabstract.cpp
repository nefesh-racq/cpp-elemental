#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using std::string;

class Empleado
{
public:
	Empleado(const string &, const string &, const string &);
	
	void setPrimerNombre(const string &);
	string getPrimerNombre() const;

	void setApellidoPaterno(const string &);
	string getApellidoPaterno() const;

	void setNroSeguroSocial(const string &);
	string getNroSeguroSocial() const;

	virtual double ingresos() const = 0;	// virtual pura
	virtual void imprimir() const;			// virtual

private:
	string primerNombre;
	string apellidoPaterno;
	string nroSeguroSocial;
};

#endif//EMPLEADO_H
