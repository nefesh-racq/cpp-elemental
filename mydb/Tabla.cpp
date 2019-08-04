#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::cerr;

#include <fstream>
using std::fstream;
//using std::reinterpret_cast;

#include "Campo.h"
#include "Tabla.h"

// ṕarametro con valor por defecto
Tabla::Tabla(string nombreTabla)
{
	setNombreTabla(nombreTabla);
}

// string tiene valor por defecto
Tabla::Tabla(string nombreTabla, Campo &fila)
{
	setNombreTabla(nombreTabla);
	setFila(fila);
}

Tabla::~Tabla()
{}

// get
string Tabla::getNombreTabla() const
{
	return _nombre;
}

Campo Tabla::getFila() const
{
	Campo temp = Fila;

	return temp;
}

// set
void Tabla::setNombreTabla(string nombreTabla)
{
	_nombre = nombreTabla;
}

void Tabla::setFila(Campo &fila)
{
	Fila.setId(fila.getId());
	Fila.setDescripcion(fila.getDescripcion());
	Fila.setValor(fila.getValor());
}

void Tabla::setFila(int id, string descripcion, string valor)
{
	Fila.setId(id);
	Fila.setDescripcion(descripcion);
	Fila.setValor(valor);
}

// operaciones de la db
bool Tabla::insert()
{
	fstream tabla(_nombre, ios::in | ios::out | ios::binary);

	if (!tabla)
	{
		cerr << "La tabla " << _nombre << " no existe.." << endl;
	}
	else
	{
		// posiconiamos el puntero al inicio del archivo
		tabla.seekg((Fila.getId() - 1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&Fila), sizeof(Campo));
		cout << "done.." << endl;
/*
		tabla.seekg(0);
		Campo fila;
		tabla.read(reinterpret_cast<char *>(&fila), sizeof(Campo));

		if (fila.getId() != 0)
			cout << fila.getId() << ", " << fila.getDescripcion() << ", " << fila.getValor() << endl;

		while (tabla.eof())
		{
			tabla.read(reinterpret_cast<char *>(&fila), sizeof(Campo));

			if (fila.getId() != 0)
				cout << fila.getId() << ", " << fila.getDescripcion() << ", " << fila.getValor() << endl;
		}
*/
		return true;
	}

	return false;
}

bool Tabla::select()
{
	//std::cout << "Tabla::select() " << _nombre << "\n";
	fstream tabla(_nombre, ios::in | ios::out | ios::binary);
	bool flag = false;

	if (!tabla)
	{
		cerr << "La tabla " << _nombre << " no existe.." << endl;
	}
	else
	{
		//cout << "archivo existe.";
		Campo fila;

		tabla.seekg(0);
		tabla.read(reinterpret_cast<char*>(&fila), sizeof(Campo));
		if (fila.getId() != 0)
		{
			flag = true;
			
			imprimirLinea(fila);
				//<< "datos seleccionados" << endl;
		}

		while (!tabla.eof())
		{

			if (fila.getId() != 0)
			{
				imprimirLinea(fila);
			}

			tabla.read(reinterpret_cast<char*>(&fila), sizeof(Campo));
		}
	}

	return flag;
}

bool Tabla::select(int id)
{
	fstream tabla(_nombre, ios::in | ios::out | ios::binary);
	bool flag = false;

	if (!tabla)
		cerr << "La tabla " << _nombre << " no existe.." << endl;
	else
	{
		Campo fila;

		tabla.seekg((id - 1) * sizeof(Campo));
		tabla.read(reinterpret_cast<char*>(&fila), sizeof(Campo));

		if (fila.getId() != 0)
		{
			flag = true;
			imprimirLinea(fila);
		}
	}

	return flag;
}

bool Tabla::update()
{
	fstream tabla(_nombre, ios::in | ios::out | ios::binary);

	if (!tabla)
	{
		cerr << "La tabla " << _nombre << " no existe.." << endl;
	}
	else
	{
		tabla.seekg((Fila.getId() - 1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&Fila), sizeof(Campo));
		return true;
	}

	return false;
}

bool Tabla::deleted()
{
	fstream tabla(_nombre, ios::in | ios::out | ios::binary);

	if (!tabla)
	{
		cerr << "La tabla " << _nombre << " no existe.." << endl;
	}
	else
	{
		Campo filaTmp;

		tabla.seekg((Fila.getId() - 1) * sizeof(Campo));
		tabla.write(reinterpret_cast<const char*>(&filaTmp), sizeof(Campo));
		return true;
	}

	return false;
}

void Tabla::imprimirLinea(const Campo &fila) const
{
	cout << fila.getId() << ", "
		<< fila.getDescripcion() << ", "
		<< fila.getValor() << endl;
}

/*
miembros datos
public:
	Campo Fila;
private:
	string _nombre;
*/