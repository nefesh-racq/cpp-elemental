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

/******************************/
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ios;
using std::left;
using std::right;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <cstdlib>
using std::exit;

int escribirOpcion();
void crearArchivoTexto(fstream &);
void actualizarRegistro(fstream &);
void nuevoRegistro(fstream &);
void eliminarRegistro(fstream &);
void mostrarRegistros(fstream &);
void imprimirLinea(ostream &, const DatosCliente &);
int obtenerCta(const char * const);

enum Opciones {IMPRIMIR = 1, ACTUALIZAR, NUEVO, ELIMINAR, VER, TERMINAR};

int main()
{
	// abre el archivo para lectura y escritura
	fstream archivo("credito.dat", ios::in | ios::out | ios::binary);

	// verificamos si se ah podico abrir el archivo
	if (!archivo)
	{
		cerr << "No se puede abrir el archivo." << endl;
		exit(1);
	}

	int opcion;	// opcion para las tareas del programa

	// permite al usuario especificar una accion
	while ((opcion = escribirOpcion()) != TERMINAR)
	{
		switch (opcion)
		{
			case IMPRIMIR:	// crea un archivo a partir del archivo existente
				crearArchivoTexto(archivo);
				break;
			case ACTUALIZAR:
				actualizarRegistro(archivo);
				break;
			case NUEVO:
				nuevoRegistro(archivo);
				break;
			case ELIMINAR:
				eliminarRegistro(archivo);
				break;
			case VER:
				mostrarRegistros(archivo);
				break;
			default:
				cerr << "Opcion incorrecta" << endl;
				break;
		}

		archivo.clear();	// restablece el indicador de fin de archivo
	}

	return 0;
}

int escribirOpcion()
{
	// muestra las opciones para el pograma
	cout << "\nEscriba su opcion" << endl
		<< "1 - almaenar un archivo de texto con formato de las cuentas" << endl
		<< "    llamado \"imprimir.txt\" para imprimirlo" << endl
		<< "2 - actualizar una cuenta" << endl
		<< "3 - agregar una nueva cuenta" << endl
		<< "4 - eliminar una cuenta" << endl
		<< "5 - visualizar los registros" << endl
		<< "6 - fin del programa\n?: ";

	int opcion;
	cin >> opcion;

	return opcion;
}

void crearArchivoTexto(fstream & leerDelArchivo)
{
	// crea un archivo de texto
	ofstream archivoImprimir("imprimir.txt", ios::out);

	// sale del programa si ofstream no puede crear el archivo
	if (!archivoImprimir)
	{
		cerr << "No se pude crear el archivo." << endl;
		exit(1);
	}

	archivoImprimir << left 
		<< setw(10) << "Cuenta" 
		<< setw(10) << "Apellido" 
		<< setw(11) << "Nombre" << right
		<< setw(10) << "Saldo"
		<< endl;

	// establece el apuntador de posicion del archivo en el
	// inicio de leerDelArchivo
	leerDelArchivo.seekg(0);

	// lee el primer registro del archivo de registro
	DatosCliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

	// copia todos los registros del archivod e regisros al
	// archivo text
	while (!leerDelArchivo.eof())
	{
		// escribe un solo registro en el archivo de text
		if (cliente.obtenerNroCta() != 0)	// omite los regisros vacios
			imprimirLinea(archivoImprimir, cliente);

		// lee el siguiente registro del archivo de registro
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));
	}
}

void actualizarRegistro(fstream &actualizarArchivo)
{
	// obtiene el numero de la cuenta que se va a actualizar
	int nroCta = obtenerCta("Escriba la cuenta que se debe actualizar");

	// desplaza el apuntador de posicion del archivo al registro correcto
	// dentro del archivo
	actualizarArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));

	// lee el primer registro del archivo
	DatosCliente cliente;

	actualizarArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

	//actualiza el registro
	if (cliente.obtenerNroCta())
	{
		imprimirLinea(cout, cliente);	// muestra los datos del cliente

		// soicita al usuario que especifique la transaccion
		cout << "\nEscriba el cargo (+) o pago (-): ";
		
		double transaccion;
		cin >> transaccion;


		// actualiza el saldo del registro
		double saldoAnterior = cliente.obtenerSaldo();
		cliente.establecerSaldo(saldoAnterior + transaccion);
		imprimirLinea(cout, cliente);	// muestra el registro

		// desplaza el apuntador de posicin del archivo
		// al registro correcto en el archivo
		actualizarArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));
		// escribe el registro actualizado sobre el registro anterior
		actualizarArchivo.write(reinterpret_cast<const char*>(&cliente), sizeof(DatosCliente));
	}
	else
		cerr << "La cuenta #" << nroCta
			<< " no tiene informacion:" << endl;

}

void nuevoRegistro(fstream &insertarEnArchivo)
{
	// obtiene el nro de cuenta que se debe crear
	int nroCta = obtenerCta("Escriba el nro de cuenta para el nuevo regisro");

	//dezpla el apuntador de posicion del archivo al registro en el archivo
	//
	insertarEnArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));

	// lee un registro del archivo
	DatosCliente cliente;
	insertarEnArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

	// creamos un registro si este no existe
	if (cliente.obtenerNroCta() == 0)
	{
		char apellidoPaterno[15];
		char primerNombre[10];
		double saldo;

		// el usuario introduce le apellido paterno, primer nombre
		// y saldo
		cout << "Escriba epallido paterno, primer nombre y saldo\n?: ";
		cin >> setw(15) >> apellidoPaterno;
		cin >> setw(10) >> primerNombre;
		cin >> saldo;

		// usamos los datos para establecer los datos a cliente
		cliente.establecerNroCta(nroCta);
		cliente.establecerPrimerNombre(primerNombre);
		cliente.establecerApellidoPaterno(apellidoPaterno);
		cliente.establecerSaldo(saldo);

		// desplaza el apuntador de posicion del archivo al registro correcto
		insertarEnArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));

		// inserta el registro al archivo
		insertarEnArchivo.write(reinterpret_cast<const char*>(&cliente), sizeof(DatosCliente));

	}
	else
		cerr << "La cuenta #" << nroCta
			<< " ya contine informacion." << endl;
}

void eliminarRegistro(fstream & eliminarDelArchivo)
{
	// obtiene el nro de cuenta que debe eliminar
	int nroCta = obtenerCta("Escriba la cuenta que desea eliminar");

	// desplaza el apuntador de posicion del archivo al registrode la cuenta
	eliminarDelArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));

	// lee el registro del archivo
	DatosCliente cliente;

	eliminarDelArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

	// eliminar el registro, si existe en el registro
	if (cliente.obtenerNroCta() != 0)
	{
		DatosCliente clienteEnBlanco;

		// posicionamos el apuntador al registro del archivo
		eliminarDelArchivo.seekg((nroCta - 1) * sizeof(DatosCliente));

		// eliminamos el registro reemplazandolo por uno en blanco
		eliminarDelArchivo.write(reinterpret_cast<const char*>(&clienteEnBlanco), 
				sizeof(DatosCliente));

		cout << "La cuenta #" << nroCta << " se elimino.\n";
	}
	else
		cerr << "La cuenta #" << nroCta << " no existe en el registro" << endl;
}

void imprimirLinea(ostream &salida, const DatosCliente &obj)
{
	salida << left << setw(10) << obj.obtenerNroCta()
		<< setw(10) << obj.obtenerApellidoPaterno()
		<< setw(11) << obj.obtenerPrimerNombre()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << obj.obtenerSaldo() << endl;
}

int obtenerCta(const char * const mensaje)
{
	int nroCta;

	do
	{
		cout << mensaje << " (1 - 100): ";
		cin >> nroCta;
	} while (nroCta < 1 || nroCta > 100);

	return nroCta;
}

void mostrarRegistros(fstream &archivo)
{
	if (archivo)
	{
		cout << "\nRegistros del Archivo" << endl
			<< left 
			<< setw(10) << "Cuenta" 
			<< setw(10) << "Apellido" 
			<< setw(11) << "Nombre" << right
			<< setw(10) << "Saldo"
			<< endl;

		// posicionamos el puntero de los registros al inicio del archivo
		// restablece el puntero al inicio del archivo
		archivo.seekg(0);

		// leemos el primer registro
		DatosCliente cliente;
		archivo.read(reinterpret_cast<char*>(&cliente), sizeof(DatosCliente));

		if (cliente.obtenerNroCta() != 0)
			imprimirLinea(cout, cliente);

		while (!archivo.eof())
		{
			archivo.read(reinterpret_cast<char *>(&cliente), sizeof(DatosCliente));

			if (cliente.obtenerNroCta() != 0)
				imprimirLinea(cout, cliente);
		}
	}
	else
		cerr << "El archvo esta vacio" << endl;
}
