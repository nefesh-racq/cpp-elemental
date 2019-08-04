// creacion y prueba de manipuladores de flujos
// no parametrizadas, definidos po el usuario.
#include <iostream>
using std::ostream;
using std::cout;
using std::flush;

// manipulador alarma /usa la secuencia de escape \a)
ostream& alarma(ostream& salida)
{
	return salida << '\a';	// emite el sonido de alerta del sistema
}

// manipulador retornoCarro /usa la secuencia de escape \r)
ostream& retornoCarro(ostream& salida)
{
	return salida << '\r';	// emite el retorno de carro
}

// manipulador tab (usa la secuencia de escape \t)
ostream& tab(ostream& salida)
{
	return salida << '\t';	// emite el tabulador
}

// manipulador finLinea (usa la secuencia de escape \n y la funcion
// miembro flush)
ostream& finLinea(ostream& salida)
{
	return salida << '\n' << flush;	// emite fin de linea parecido a endl
}

int main()
{
	// usa los manipuladores tab y finLinea
	cout << "Prueba del manipulador tab: " << finLinea
		<< 'a' << tab << 'b' << tab << 'c' << finLinea;

	cout << "Prueba de los manipuladores retornoCarro y alarma:"
		<< finLinea << "..........";

	cout << alarma;	// usa el manipulador alarma

	// usa ls manipuladores retornoCarro y finLinea
	cout << retornoCarro << "-----" << finLinea;

	return 0;
}
