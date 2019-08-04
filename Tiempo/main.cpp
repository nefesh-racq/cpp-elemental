#include <iostream>
using std::cout;

#include "Tiempo.h"

int main()
{
	Tiempo t;

	t.establecerTiempo(18, 32, 54);
	cout << "hora universal\n";
	t.imprimirUniversal();
	cout << "\nhora estandar\n";
	t.imprimirEstandar();
	cout << "\n";

	return 0;
}

