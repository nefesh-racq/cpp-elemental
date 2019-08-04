#ifndef STRING_H
#define STRING_H

#include <iostream>
using std::ostream;
using std::istream;

class String
{
	friend ostream &operator<<(ostream &, const String &);
	friend istream &operator>>(istream &, String &);

public:
	String(const char * = "");	// constructor
	String(const String &);		// constructor de copia
	~String();					// destructor

	const String &operator=(const String &);	// operador de asignacion
	const String &operator+=(const String &);	// operador de concatenacion

	bool operator!() const;					// el obj es vacio
	bool operator==(const String &) const;	// evalua s1 == s2
	bool operator<(const String &) const;	// evalua s1 < s2

	// evalua si != s2
	bool operator!=(const String &derecho) const
	{
		return !(*this == derecho);
	}

	// evalua s1 > s2
	bool operator>(const String &derecho) const
	{
		return derecho < *this;
	}

	// evalua s1 <= s2
	bool operator<=(const String &derecho) const
	{
		return !(derecho < *this);
	}

	// s1 >= s2
	bool operator>=(const String &derecho) const
	{
		return !(*this < derecho);
	}

	char &operator[](int);	// lvalue modificable
	char operator[](int) const;	// rvalue
	String operator()(int, int = 0) const;	// devuelve una subcadena
	int getLongitud() const;	// retorna el tamaño de la cadena

private:
	int longitud;	// longitud de la cadena
	char *sPtr;		// puntero para la cadena

	void setString(const char*);	// funcion utilitaria
};

#endif//STRING_H

// definicion de las funciones de la clase String
//
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstring>
using std::strcmp;
using std::strcpy;
using std::strcat;
using std::strncpy;

#include <cstdlib>
using std::exit;

//#include "String.h"
String::String(const char *s)
	: longitud((s != 0) ? strlen(s) : 0)
{
	cout << "Constructo de conversion (y predeterminado): " << s << endl;
	setString(s);	// usamos la funcion utilitaria
}

// constructor de copia
String::String(const String &copia)
	: longitud(copia.longitud)
{
	cout << "constructor de copia: " << copia.sPtr << endl;
	setString(copia.sPtr);	// usmos la funcion utilitaria
}

// destructor
String::~String()
{
	cout << "Destructor: " << sPtr << endl;
	delete [] sPtr;
}

// operador = sobrecargado para evitar la auto-asignacion
const String &String::operator=(const String &derecho)
{
	cout << "se llamo a operator=" << endl;

	if (&derecho != this)	// evita la autoasignacion
	{
		delete [] sPtr;
		longitud = derecho.longitud;	// nueva longitud
		setString(derecho.sPtr);		// usamos la funcion utilitaria
	}
	else
		cout << "Intento de asignar un obj String a si mismo " << endl;

	return *this;
}

// concatena el operando derecho a este
const String &String::operator+=(const String &derecho)
{
	size_t nuevaLongitud = longitud + derecho.longitud;	// nueva longitud
	char *tempPtr = new char[nuevaLongitud + 1];	// crea la memoria

	strcpy(tempPtr, sPtr);	// copia sPtr
	// usamos aritmetica de punteros
	strcpy(tempPtr + longitud, derecho.sPtr);	// copia derecho.sPtr

	delete [] sPtr;	// liberamos memoria para asignarla otra
	sPtr = tempPtr;	// asigna la nueva memoria a sPtr
	longitud = nuevaLongitud;	// asigna la nueva longitud

	return *this;
}

// esta vacio ?
bool String::operator!() const
{
	return longitud == 0;
}

// los obj son iguales ?
bool String::operator==(const String &derecho) const
{
	return strcmp(sPtr, derecho.sPtr) == 0;
}

// el objeto es menor que el obj string derecho ?
bool String::operator<(const String &derecho) const
{
	return strcmp(sPtr, derecho.sPtr) < 0;
}

// devuelve referencia al caracter en el obj string como un
// lvalue modificable
char &String::operator[](int subindice)
{
	// evalua si el subindice esta fuera de rango
	if (subindice < 0 || subindice >= longitud)
	{
		cerr << "Error: subindice " << subindice
			<< " fuera de rango" << endl;
		exit(1);
	}

	return sPtr[subindice];
}

// devuelve referencia al caracter en el objeto String como
// rvalu
char String::operator[](int subindice) const
{
	// evalua si el indice esta fuera del rango
	if (subindice < 0 || subindice >= longitud)
	{
		cerr << "Error: subindice " << subindice
			<< " fuera de rango" << endl;
		exit(1);
	}

	return sPtr[subindice];
}

// devuelve una subcadena que empieza en indice y tiene una sublongitud
String String::operator()(int indice, int subLongitud) const
{
	// si el indice  esta fuera de rango o la ongitud de subcadena<0
	// devuelve un objeto string vacio
	if (indice < 0 || indice >= longitud || subLongitud < 0)
		return "";	// se convierte en obj string de manera automatica

	// determina la longitud de la subcadena
	int lon;

	if ((subLongitud == 0) || (indice + subLongitud > longitud))
		lon = longitud - indice;
	else
		lon = subLongitud;

	// asigna un arreglo temporal para la subcadena
	// y el caracter nulo de terminacion
	char *tempPtr = new char[lon + 1];

	// copia subcadena en arreglo char y termina la cadena
	strncpy(tempPtr, &sPtr[indice], lon);
	tempPtr[lon] = '\0';

	// crea objeto string temporal que contiene la subcadena
	String tempString(tempPtr);
	
	delete [] tempPtr;	// elimina el objeto temporal
	tempPtr = 0;

	return tempString;	// devuelve copia del objeto
}

// devuelve a longitud de la cadena
int String::getLongitud() const
{
	return longitud;
}

// funcion utilitaria
void String::setString(const char *string2)
{
	sPtr = new char[strlen(string2) + 1];	//  reserva memoria
	if (string2 != 0)
		strcpy(sPtr, string2);
	else
		sPtr[0] = '\0';
}

// operador de salida sobrecargado
ostream &operator<<(ostream &salida, const String &objeto)
{
	salida << objeto.sPtr;

	return salida;	// permite la asignacion en cascada
}

// operador de entrada sobrecargado
istream &operator>>(istream &entrada, String &objeto)
{
	char temp[100];	// búfer para almacenar la entrada

	entrada >> setw(100) >> temp;
	objeto = temp;	// usamos el operador = de la clas string

	return entrada;	// permite la asignacion en cascada
}

/*****************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;

//#include "String.h"

int main()
{
	String s1("feliz");
	String s2(" cumpleaños");
	String s3;

	// evalua los operadores de igualdad y relacionales sobrecargados
	cout << "s1 es \"" << s1 << "\"; s2 es \"" << s2
		<< "\": s2 es \"" << s3 << '\"'
		<< boolalpha << "\n\nLos resultados de comparar s2 y s1:"
		<< "\ns2 == s1 produce " << ( s2 == s1 )
		<< "\ns2 != s1 produce " << ( s2 != s1 )
		<< "\ns2 >  s1 produce " << ( s2 > s1 )
		<< "\ns2 <  s1 produce " << ( s2 < s1 )
		<< "\ns2 >= s1 produce " << ( s2 >= s1 )
		<< "\ns2 <= s1 produce " << ( s2 <= s1 );

	// evalua el operador vacio (!) sobrecargado de Strng
	cout << "\n\nEvaluando !s3:" << endl;
	
	if (!s3)
	{
		cout << "s3 esta vacio: se asignara s1 a s3:" << endl;
		s3 = s1;	// usa el operador sobrecargado
		cout << "s3 es\"" << s3 << "\"";
	}

	// evalua el operador de concatenacion sobrecargado
	cout << "\n\ns1 += s2 produxe s1 = ";
	s1 += s2;	// usa el operador += sobrecargado
	cout << s1;

	// evalua el contructor de conversion
	cout << "\n\ns1 += \" a ti\" produce " << endl;
	s1 += " a ti";	// usa el constructor de conversion
	cout << "s1 = " << s1 << " \n\n";

	// evalua el operador () de llamada a funcion sobrecargado para cadenas
	cout << "La subcadena de s1 empezando en\n"
		<< "la ubicacion 0 para 17 caracteres, s1(0, 17), es:\n"
		<< s1(0, 17) << "\n\n";

	// evalua la opcion "hasta el final de String" de la subcadena
	cout << "La subcadena de s1 empezando en \n"
		<< "la ubicacion 18, s1(18), es: "
		<< s1(18) << "\n\n";

	// evalua el constructor de copia
	String *s4Ptr = new String(s1);
	cout << "\n*s4ptr = " << *s4Ptr << "\n\n";

	// evalua el operador de asignacion (=) con la auto asignacioN
	cout << "asignacion *s4ptr a *s4Ptr " << endl;
	*s4Ptr = *s4Ptr;	// evalue el operador de asignacion sobrecargado =
	cout << "*s4Ptr = " << *s4Ptr << endl;

	// evalua el destructor
	delete s4Ptr;

	// evalua el operador de subindice[] para crear lvalues modificables
	s1[0] = 'F';
	s1[6] = 'C';
	cout << "\ns1 despues de s1[0] = 'F' y s1[6] = 'C' : "
		<< s1 << "\n\n";

	// evalua subindice fuera de rango
	cout << "Intento de asignar 'd' a s1[30] produce:. ";
	s1[30] = 'd';

	return 0;
}

