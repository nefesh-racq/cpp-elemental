// definicion de la clase Datoscliente, 
#include <string>
using std::string;

#include <cstring>
using std::strncpy;

class DatosCliente
{
public:
	// constructor predeterminado
	DatosCliente(int = 0, string = "", string = "", double = 0.0);

	// funciones de acceso para numeroCuenta
	void establecerNroCta(int);
	int obtenerNroCta() const;

	// funciones de acceso apr apellidoPaterno
	void establecerApellidoPaterno(string);
	string obtenerApellidoPaterno() const;

	// primer nombre
	void establecerPrimerNombre(string);
	string obtenerPrimerNombre() const;

	// saldo
	void establecerSaldo(double);
	double obtenerSaldo() const;

private:
	int numeroCta;
	char apellidoPaterno[15];
	char primerNombre[10];
	double saldo;
};

DatosCliente::DatosCliente(int vNroCta, string vApPaterno,
	string vPrimerNombre, double vSaldo)
{
	establecerNroCta(vNroCta);
	establecerApellidoPaterno(vApPaterno);
	establecerPrimerNombre(vPrimerNombre);
	establecerSaldo(vSaldo);
}

int DatosCliente::obtenerNroCta() const
{
	return numeroCta;
}

void DatosCliente::establecerNroCta(int vNroCta)
{
	numeroCta = vNroCta;
}

string DatosCliente::obtenerApellidoPaterno() const
{
	return apellidoPaterno;
}

void DatosCliente::establecerApellidoPaterno(string vApPaterno)
{
	// son 15 caracteres del apellido paterno
	const char* apellidoP = vApPaterno.data();
	int longitud = vApPaterno.size();
	
	longitud = (longitud < 15 ? longitud : 14);
	strncpy(apellidoPaterno, apellidoP, longitud);
	apellidoPaterno[longitud] = '\0';	// adjuntamos el caracter nulo
}

string DatosCliente::obtenerPrimerNombre() const
{
	return primerNombre;
}

void DatosCliente::establecerPrimerNombre(string vPrimerNombre)
{
	// son 10 caracteres para el nombre
	const char* primerNom = vPrimerNombre.data();
	int longitud = vPrimerNombre.size();

	longitud = (longitud < 10 ? longitud : 9);
	strncpy(primerNombre, primerNom, longitud);
	primerNombre[longitud] = '\0';
}

double DatosCliente::obtenerSaldo() const
{
	return saldo;
}

void DatosCliente::establecerSaldo(double vSaldo)
{
	saldo = vSaldo;
}

/***************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ios;

using std::fixed;
using std::right;
using std::left;
using std::showpoint;

using std::ostream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <fstream>
using std::ofstream;
using std::fstream;
using std::ifstream;

#include <cstdlib>
using std::exit;

// creacion de un archivo de acceso aleatorio
/*
int main()
{
	ofstream creditoSalida("credito.dat", ios::out | ios::binary);

	// verificamos si el archivo se creo correctamente
	if (!creditoSalida)
	{
		cerr << "No se pudo abrir el archivo. " << endl;
		exit(1);
	}

	DatosCliente clienteEnBlando;

	// 
	for (int i = 0; i < 100; i++)
		creditoSalida.write(reinterpret_cast<const char*>(&clienteEnBlando),
				sizeof(DatosCliente));

	return 0;
}*/

// escritura en un archivo aleatorio
/*
int main()
{
	int nroCta;
	char apellidoPaterno[15];
	char primerNombre[10];
	double saldo;

	fstream creditoSalida("credito.dat", ios::in | ios::out | ios::binary);

	// sale del programa si fstream no puede abrir el archivo
	if (!creditoSalida)
	{
		cerr << "No se puede abrr el archivo. " << endl;
		exit(1);
	}
	cout << "Escriba el numero de cuenta (de 1 - 100 y 0 para terminar).\n";

	// requiere que el usuario especifique el numero de cuenta
	DatosCliente cliente;
	cin >> nroCta;

	// el usuario introduce informacion, la cual se copia en el archivo
	while (nroCta > 0 && nroCta <= 100)
	{
		// el usuario intoduce el apellido paterno, primer nombre y saldo
		cout << "Escriba apellido paterno, primer nombre y saldo\n?: ";
		cin >> setw(15) >> apellidoPaterno;
		cin >> setw(10) >> primerNombre;
		cin >> saldo;

		// establece los valores de nroCta, apellidoPaterno, primerNombre 
		// y saldo del registro
		cliente.establecerNroCta(nroCta);
		cliente.establecerApellidoPaterno(apellidoPaterno);
		cliente.establecerPrimerNombre(primerNombre);
		cliente.establecerSaldo(saldo);

		// busca la posicin en el archivo de registro especifico
		creditoSalida.seekp((cliente.obtenerNroCta() - 1) * sizeof(DatosCliente));

		// escribe la informacion especificada por el usuario en el archivo
		creditoSalida.write(reinterpret_cast<const char*>(&cliente), sizeof(DatosCliente));

		// permite al usuario escribir otro numero de cuenta
		cout << "Escriba el numero de cuenta\n?: ";
		cin >> nroCta;
	}

	return 0;
}
*/

// lectura secuencial de un archivo de acceso aleatorio
void imprimirLinea(ostream&, const DatosCliente&);

int main()
{
	ifstream creditoEntrada("credito.dat", ios::in | ios::binary);

	// sale del programa si ifstream no puede abrir el archivo
	if (!creditoEntrada)
	{
		cerr << "No se puede abrir el archivo." << endl;
		exit(1);
	}

	cout << left << setw(10) << "Cuenta" << setw(16)
		<< "Apellido" << setw(11) << "Nombre" << left
		<< setw(10) << right << "Saldo" << endl;

	DatosCliente cliente;	// 

	// lee el primer registro del archivo
	creditoEntrada.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

	// lee todos los registros del archivo
	while (creditoEntrada && !creditoEntrada.eof())
	{
		// muestra un registro
		if (cliente.obtenerNroCta() != 0)
			imprimirLinea(cout, cliente);

		// lee el siguiente registro del archivo
		creditoEntrada.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));
	}

	return 0;
}

void imprimirLinea(ostream& out, const DatosCliente& obj)
{
	out << left << setw(10) << obj.obtenerNroCta()
		<< setw(16) << obj.obtenerApellidoPaterno()
		<< setw(11) << obj.obtenerPrimerNombre()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << obj.obtenerSaldo() << endl;
}
