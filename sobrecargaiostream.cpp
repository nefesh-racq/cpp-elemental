// sobrecarga de operadores de entrada y salida
#ifndef NUMERO_TELEFONICO_H
#define NUMERO_TELEFONICO_H

#include <iostream>
using std::ostream;
using std::istream;

#include <string>
using std::string;

class NumeroTelefonico
{
	friend ostream &operator<<(ostream &, const NumeroTelefonico &);
	friend istream &operator>>(istream &, NumeroTelefonico &);

public:
	string codigoArea;	// codigo de area de 3 digitos
	string intercambio;	// intercambio de 3 digitos
	string linea;		// linea de 4 digitos
};

#endif//NUMERO_TELEFONICO_H

#include <iomanip>
using std::setw;

// sobrecarga del operador de insercion de flujo,
// no puede ser una funcion miembro si deseamos invocarlo con
// cout << unNumeroTelefonico;
ostream &operator<<(ostream &salida, const NumeroTelefonico &numero)
{
	salida << "(" << numero.codigoArea << ") "
		<< numero.intercambio << "-" << numero.linea;

	return salida;	// permtie cout << a << b << c;
}

// sobrecarga de operador de extraccion de flujo
// no puede ser una funcion miembro si deseamos invocarlo con
// cin >> unNumeroTelefonico;
istream &operator>>(istream &input, NumeroTelefonico &numero)
{
	input.ignore();	// omite (
	input >> setw(3) >> numero.codigoArea;	// recibe el codigo de area
	input.ignore(2);	// omite ) y espacio
	input >> setw(3) >> numero.intercambio;	// recibe intercambio
	input.ignore();	// omite el guion corto (-)
	input >> setw(4) >> numero.linea;	// recibe linea

	return input;
}

/***************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	NumeroTelefonico telefono;	// instancia un objeto llamado telefono

	cout << "Escriba el numero telefonico en la forma (123) 456-7890:" << endl;

	// cin >> telefono invoca a operator>> generando de manera
	// implicita la llamada a la funcion global operator>>(cin, telefono)
	cin >> telefono;

	cout << "El numero telefonico introducido fue: ";

	// cout << telefono invoca a operator<< llamando de manera
	// implicita a la funcion global operator<<(cout, telefono)
	cout << telefono << endl;

	return 0;
}

