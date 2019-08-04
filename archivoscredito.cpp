// programa de solicitu de crédito
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::fixed;
using std::ios;
using std::left;
using std::right;
using std::showpoint;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

enum TipoSolicitud {SALDO_CERO = 1, SALDO_CREDITO, SALDO_DEBITO, TERMINAR};

int obtenerSolcitud();
bool debeMostrar(int, double);
void imprimirLinea(int, const string, double);

int main()
{
	// el onstructor de ifstream abre el archivo
	ifstream archivo("clientes.dat", ios::out);

	// sale del programa si ifstream no puede abrir el archivo
	if (!archivo)
	{
		cerr << "No se puede abrir el archivo." << endl;
		exit(1);
	}

	int solicitud;
	int cuenta;
	char nombre[50];
	double saldo;

	// obtiene la soliictud del usuaio (por ejem, saldo, credito debito)
	solicitud = obtenerSolcitud();

	// procesa la solicitud
	while (solicitud != TERMINAR)
	{
		switch (solicitud)
		{
			case SALDO_CERO:
				cout << "\nCuentas con saldo en cero:\n";
				break;
			case SALDO_CREDITO:
				cout << "\nCuentas con saldo de credito:\n";
				break;
			case SALDO_DEBITO:
				cout << "\nCuentas con saldo de debito:\n";
				break;
			default:
				cout << "Ingrese una opcion valida." << endl;
		}

		// lee la cuenta, nombre y saldo
		archivo >> cuenta >> nombre >> saldo;

		// muestra el contenido del archivo hasta EOF
		while (!archivo.eof())
		{
			// muestra el registro
			if (debeMostrar(solicitud, saldo))
				imprimirLinea(cuenta, nombre, saldo);

			// lee el archivo
			archivo >> cuenta >> nombre >> saldo;
		}

		archivo.clear();	// restablece eof para la siguiente entrada
		archivo.seekg(0);	// se repocisona el inicio del archivo
		solicitud = obtenerSolcitud();	// obtiene la solicitud del usuario
	}

	cout << "Fin del programa." << endl;

	return 0;
}

// obtiene la solicitud desde teclado
int obtenerSolcitud()
{
	int solicitud;

	// mensaje de las opciones para el usuario
	cout << "\nEscriba la opcion" << endl
		<< "1 - Listar cuentas con saldos en cero." << endl
		<< "2 - Listar cuentas con saldos de credito." << endl
		<< "3 - Listar cuentas con saldos de debito." << endl
		<< "4 - Finalizar ejecucion." << fixed << showpoint;

	do
	{
		cout << "\n?: ";
		cin >> solicitud;
	} while (solicitud < SALDO_CERO && solicitud > TERMINAR);

	return solicitud;
}

// determina si se va mostrar o no el registro dado
bool debeMostrar(int tipo, double saldo)
{
	// determina si se va mostrar el saldo en cero
	if (tipo == SALDO_CERO && saldo == 0)
		return true;

	// saldos negativos "credito"
	if (tipo == SALDO_CREDITO && saldo < 0)
		return true;

	// saldo positivo "debito"
	if (tipo == SALDO_DEBITO && saldo > 0)
		return true;

	return false;
}

// imprime los datos
void imprimirLinea(int cuenta, const string nombre, double saldo)
{
	cout << left << setw(10) << cuenta << setw(13) << nombre
		<< setw(7) << setprecision(2) << right << saldo << endl;
}
