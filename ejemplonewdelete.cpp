// practica uso de new delete
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;
using std::strcpy;

void asignarChar(const char *);

int main()
{
	const char *cad2 = "otra cadena";
	char *cad;
	char cad1[] = "esto es una cadena";

	cad = new char[strlen(cad1) + 1];
	strcpy(cad, cad1);

	cout << cad << " = " << strlen(cad) << endl;

	delete [] cad;
	cad = 0;	// quitamos la direccion de memoria asignada

	cad = new char[strlen(cad2) + 1];
	strcpy(cad, cad2);
	cout << cad << " = " << strlen(cad) << endl;
	
	asignarChar("cadena de parametro");
	
	return 0;
}

// recibe como parametro una cadena const
void asignarChar(const char *c)
{
	char *ca = new char[strlen(c) + 1];

	strcpy(ca, c);
	cout << ca << endl;

	delete [] ca;
	ca = 0;

	int *a = new int(5555555);
	cout << *a << endl,
	delete a;
	a = 0;
}

