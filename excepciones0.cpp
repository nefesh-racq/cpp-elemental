// manejo de excepciones, intento de dividir entre cero
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>		// archivo de encabezado stdexcept contiene runtime_error
using std::runtime_error;	// clase runtime_error de la biblioteca estandar de c++

// los objetos excepcionDivisionEntreCero deben lanzarse por las
// funciones al detectar las excepciones de division entre cero
class ExcepcionDivisionEntreCero : public runtime_error
{
public:
	// el contructor especifica el mensaje de error predeterminado
	ExcepcionDivisionEntreCero()
		: runtime_error("intento de dividir entre cero") {};
};

// realiza la division y lanza un objeto ExcepcionDivisionEntreCero
// si dividi una excepcion de division entre cero
double cociente(int numerador, int denominador)
{
	// lanza a ExcepcionDivisionEntreCero si intenta la division
	if (denominador == 0)
		throw ExcepcionDivisionEntreCero();	// termina la funcion

	// devuelve el resultado de la division
	return static_cast<double>(numerador) / denominador;
}

int main()
{
	int numerador;
	int denominador;
	double resultado;

	cout << "Escriba dos enteros (fin de archivo para terminar): ";

	// permite al usuario introducir dos enteros para la division
	while (cin >> numerador >> denominador)
	{
		// el bloque try contiene codigo que podria lanzar una
		// excepcion y codigo que no se debe ejecutar si ocurre 
		// la excepcion
		try
		{
			resultado = cociente(numerador, denominador);
			cout << "El cociente es: " << resultado << endl;
		}
		catch (ExcepcionDivisionEntreCero &e)	// maneja una excepcion que se divide entre cero
		{
			cout << "Ocurrio una excepcion: "
				<< e.what() << endl;
		}

		cout << "\nEscriba dos enteros (fin de archivo para terminar)";
	}

	return 0;
}
