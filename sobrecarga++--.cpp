#include <iostream>
using std::ostream;

class Fecha
{
	friend ostream &operator<<(ostream &, const Fecha &);

public:
	Fecha(int m = 1, int d = 1, int a = 1990);
	void setFecha(int, int, int);
	Fecha &operator++();	// operador de preincremento
	Fecha operator++(int);	// operador postincremento
	const Fecha &operator+=(int);	// suma dias, modifica el objeto
	bool anioBisiesto(int) const;	// ¿es un año bisiesto ?
	bool finDeMes(int) const;		// ¿esta la fecha en fin de mes?

private:
	int mes;
	int dia;
	int anio;

	static const int dias[];
	void ayudaIncremento();
};

// inicializa miembro estatico a nivel de archivo
// una copia a nivel de clase
const int Fecha::dias[] = 
			{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// constr
Fecha::Fecha(int m, int d, int a)
{
	setFecha(m, d, a);
}

// estabkece ka fecha
void Fecha::setFecha(int mm, int dd, int aa)
{
	mes = ( mm >= 1 && mm <= 12 ) ? mm : 1;
	anio = ( aa >= 1900 && aa <= 2100 ) ? aa : 1900;

	// prueba si es año bisiesto
	if ( mes == 2 && anioBisiesto( anio ) )
		dia = ( dd >= 1 && dd <= 29 ) ? dd : 1;
	else
		dia = ( dd >= 1 && dd <= dias[ mes ] ) ? dd : 1;
}

// operador preincremento sobrecargado
Fecha &Fecha::operator++()
{
	ayudaIncremento();	// incrementa la fecha

	return *this;
}

// operador postincremento sobrecargado: observe que el parametro
// no tiene un nombre
Fecha Fecha::operator++(int)
{
	Fecha temp = *this;	// contiene el estado actual del objeto
	ayudaIncremento();

	// devuelve el objeto temporal almacenado y sin incrementar
	return temp;	// devuelve un valor, no una referencia
}

// suma el nro especiicado de dias a la fecha
const Fecha &Fecha::operator+=(int diasAdicionales)
{
	for (int i = 0; i < diasAdicionales; i++)
		ayudaIncremento();

	return *this;
}

// si el año es bisieto devuelve true de lo contrario devuelve false
bool Fecha::anioBisiesto(int anioPrueba) const
{
	if (anioPrueba % 400 == 0 ||
		(anioPrueba % 100 != 0 && anioPrueba % 4 == 0))
		return true;	// un año bisiesto
	else
		return false;	// no es año bisiesto
}

// determina si el dia es el ultimo del mes
bool Fecha::finDeMes(int diaPrueba) const
{
	if (diaPrueba < 31)
		return diaPrueba == 29;	// ultimo da de feb, en año bisiesto
	else
		return diaPrueba == dias[mes];
}


// funcion para ayudar a incrementar la fecha
void Fecha::ayudaIncremento()
{
	// dia no es fin de mes
	if (!finDeMes(dia))
		dia++;
	else 
		if (mes < 12)	// dia es fin de mes y mes < 12
		{
			mes++;		// incrementa el mes
			dia = 1;	// primer dia del mes nuevo
		}
		else // ultimo da del año
		{
			anio++;		// incrementa año
			mes = 1;	// primer mes del año nuevo
			dia = 1;	// primer dia del nuevo mes
		}
}

// operador de salida sobrecargado
ostream &operator<<(ostream &salida,  const Fecha &d)
{
	static const char *nombreMes[13] = {"", "Enero", "Febrero",
				"Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto",
				"Septiembre", "Octubre", "Noviembre", "Diciembre" };

	salida << nombreMes[d.mes] << ' ' << d.dia << ", " << d.anio;

	return salida;
}

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Fecha d1;	// valor predeterminado: Enero 1, 1900
	Fecha d2(12, 27, 1992);
	Fecha d3(0, 99, 8045);

	cout << "d1 es " << d1 << "\nd2 es " << d2 << "\nd3 es " << d3;
	cout << "\n\nd2 += 7 es " << (d2 += 7);

	d3.setFecha(2, 28, 1992);
	cout << "\n\n d3 es " << d3;
	cout << "\n++d3 es " << ++d3 << "(año bisiesto permite dia 29)";

	Fecha d4(7, 13, 2002);

	cout << "\n\nPrueba del operador preincremento:\n"
		<< "  d4 es " << d4 << endl;
	cout << "++d4 es " << ++d4 << endl
		<< "  d4 es " << d4;

	cout << "\n\nPrueba del operador postincremento:\n"
		<< "  d4 es " << d4 << endl;
	cout << "d4++ es " << d4++ << endl
		<< "  d4 es " << d4 << endl;

	return 0;
}
