// ejemplo de llamada en cascada
#ifndef FECHA_H
#define FECHA_H

class Fecha
{
public:
	Fecha(int = 1000, int = 1, int = 1);
	// metodos set
	Fecha &setAnio(int);
	Fecha &setMes(int);
	Fecha &setDia(int);

	// metodos get
	int getAnio() const;
	int getMes() const;
	int getDia() const;
	// metodos gete tipo char
	const char *getMesLiteral() const;
	//char *getDiaLiteral() const;
	
	// metodos imprimir
	void imprimir() const;

private:
	int anio;
	int mes;
	int dia;
};

#endif // FECHA_H

/************************************************/
// definicion de las funciones
#include <iostream>
using std::cout;
using std::endl;


Fecha::Fecha(int aa, int mm, int dd) : anio(aa), mes(mm), dia(dd)
{ ; }

Fecha &Fecha::setAnio(int a)
{
	anio = a;

	return *this;
}

Fecha &Fecha::setMes(int m)
{
	mes = m;

	return *this;
}

Fecha &Fecha::setDia(int d)
{
	dia = d;

	return *this;
}

int Fecha::getAnio() const
{
	return anio;
}

int Fecha::getMes() const
{
	return mes;
}

int Fecha::getDia() const
{
	return dia;
}

const char *Fecha::getMesLiteral() const
{
	// el array debe ser const char : porque son punteros a cadenas constantes
	static const char *meses[13] = {"NONE", "ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

	return meses[getMes()];
}

/* esto esta mal porque tenemos dias de mas del nro 7
char *Fecha::getDiaLiteral() const
{
	static char *dias[8] = {"NONE", "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};

	return dias[getDia()];
}
*/

// imprime la fecha aaaa:mm:dd
void Fecha::imprimir() const
{
	cout << getAnio() << ":" << getMesLiteral() << ":" << getDia() << endl;
}

/****************************************/
// manejo de la clase fecha

int main()
{
	Fecha f(1999, 10, 10);

	cout << "\nFecha antes de la llamada en cascada\n";
	f.imprimir();

	cout << "\nFecha despues de la llamada en cascada\n"
		<< "fecha.setAnio(2000).setMes(10).setDia(10);\n";
	f.setAnio(2000).setMes(11).setDia(11);
	f.imprimir();

	// uso de puntero y referencia aun objeto
	Fecha *fPtr;
	Fecha f0;

	fPtr = &f0;
	fPtr->imprimir();

	cout << endl;

	// solo setAnio() es llamado mediante el operador -> los demas con punto por q son referencias
	fPtr->setAnio(1888).setMes(10).setDia(21);
	fPtr->imprimir();
	cout << endl;	

	// una referencia se debe asignar en su declaracion oh da error
	Fecha &fRef = f0;

	fRef.imprimir();
	fRef.setAnio(1777).setMes(12).setDia(12);
	fRef.imprimir();
	cout << endl;

	// reserva dinamica de memoria
	Fecha *fPtr0 = new Fecha(9999, 9, 90);

	fPtr0->imprimir();
	fPtr0->setAnio(2010).setMes(10).setDia(20);
	fPtr->imprimir();

	// liberamos la memoria de fPtr
	delete fPtr0;

	//const char *meses[14] = {"NONE", "ENE", "FEB", "MAR"};

	return 0;
}

