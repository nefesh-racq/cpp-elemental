// manejo de la base de datos
#include <iostream>
using std::endl;
using std::cout;
using std::cin;
using std::cerr;

#include <string>
using std::string;

#include "Campo.h"
#include "Tabla.h"
#include "MyDB.h"

void mensaje();
//void interpretar(string);

int main()
{
	MyDB myApp("tabla0.dat");
	string sentencia;

	mensaje();

	// ejecuta el programa hasta que se ingresa
	// fin de archivo ^Z
	while (true)
	{
		cout << ":$ ";
		//getline(cin, sentencia);
		
		/*
		myApp.insert(23, "descripcion vacia", "123.00");
		myApp.insert(22, "operacioens", "456.00");
		myApp.insert(10, "oliver atom", "123.00");

		myApp.select();
		*/

		cin >> sentencia;

		if (sentencia == "select")
		{
			int id;

			cout << "id: ";
			cin >> id;

			// cualquier numero diferente de 0 es todo
			if (id != 0)
			{
				if (myApp.select(id))
					cout << "done.." << endl;
				else
					cout << "no data.." << endl;
			}
			else// if (sentencia == "*")
			{
				cout << "list.." << endl;
			
				if (myApp.select())
					cout << "done.." << endl;
				else
					cout << "table is empty.." << endl;
			}

			cout << endl;
		}
		else if (sentencia == "insert")
		{
			int id;
			string des = "";
			string valor;

			cout << "id: ";
			cin >> id;
			cout << "descripcion: ";
			cin >> des;
			cout << "valor: ";
			cin >> valor;

			if (myApp.insert(id, des, valor))
				cout << "insert... done..." << endl;

			cout << endl;
		}
		else if (sentencia == "update")
		{
			int id;
			string des;
			string valor;

			cout << "id: ";
			cin >> id;

			if (id != 0)
			{
				cout << "descripcion: ";
				cin >> des;
				cout << "valor: ";
				cin >> valor;

				if (myApp.update(id, des, valor))
					cout << "done.. update.." << endl;
			}

			cout << endl;
		}
		else if (sentencia == "delete")
		{
			int id;

			cout << "id: ";
			cin >> id;

			if (id != 0)
			{
				if (myApp.deleted(id))
					cout << "deleted done.." << endl;
				else
					cout << "error no data.." << endl;
			}

			cout << endl;
		}

		interpretar(sentencia);
	}

	return 0;
}

void mensaje()
{
	cout << "************************************************************\n"
		<< "* Simulador de sql sobre un archivo.                       *\n"
		<< "* operaciones admitidas insert, select, update, delete     *\n"
		<< "* tabla(id, descripcion, valor)                            *\n"
/*		<< "* insert MITABLA "
		<< "* values VALOR1, VALOR2, VALOR3 \n"
		<< "* update MITABLA "
		<< "* set campo1=VALOR1, campo2=VALOR2, campo3=VALOR3"
		<< "* where id=ID\n"
		<< "select * "
		<< "from MITABLA "
		<< "where campo=VALOR\n"
		<< "delete from MITABLA"
		<< " where id=ID\n" */
		<< "***************** INGRESE ^Z para terminar *****************\n\n";
}
/*
void interpretar(string sentencia)
{
	// leer cadena completa hasta fin de linea
	// separar los tokens
	// clasificar los token, palabras reservadas, varables
	// 
}
*/
