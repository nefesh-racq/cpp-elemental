#include <iostream>
using std::endl;
using std::cout;
using std::cin;


#include "Nodo.h"
#include "MyApp.h"

MyApp::MyApp()
	: GAMEOVER(false)
{
	arbolPtr = new ArbolBinario();
}


MyApp::~MyApp()
{
	delete arbolPtr;
}

void MyApp::play()
{
	message();

	char opcion;
	string animal;
	string cualidad;
	Nodo *nodoPtr = arbolPtr->begin();

	cin >> opcion;

	if (opcion != 's')
		GAMEOVER = true;

	while (!GAMEOVER) {
		if (nodoPtr->derPtr == NULL && nodoPtr->izdPtr == NULL)
		{
			cout << "Estas pensando en un" << nodoPtr->getInfo() << ". (s/n) ?: ";
			cin >> opcion;

			if (opcion == 's')
			{
				cout << "Adivine..! soy bueno en esto..! XD\n";
				GAMEOVER = true;
			}
			else
			{
				cout << "Que animal era en el que pensabas. dime..!?";
				cin >> animal;
				cout << "Que diferencia hay con un " << nodoPtr->getInfo() << ".? ";
				cin >> cualidad;

				arbolPtr->insert(animal, cualidad);
				GAMEOVER = false;
			}
		}
		else
		{
			cout << "El animal que piensas " << nodoPtr->getInfo() << ".(s/n)?: ";
			cin >> opcion;

			if (opcion == 's')
				nodoPtr = nodoPtr->izdPtr;
			else
				nodoPtr = nodoPtr->derPtr;
		}
	}

	cout << "\nGracias por jugar conmigo.. :)..\n";
}


void MyApp::message()
{
	cout << "**************************************************************************\n"
		<< "* ejemplo de arbol binario muy simple                                    *\n"
		<< "* adivina el animal en el que estas pensando, y aprende segun va jugando *\n"
		<< "* cuando termina el programa olvida todo lo aprendido                    *\n"
		<< "* ENTRADA DE DATOS:                                                      *\n"
		<< "* (SI) s, (NO) n                                                         *\n"
		<< "**************************** nefesh - racq *******************************\n";

	cout << "Quieres jugar conmigo..(s/n)!?";
}
