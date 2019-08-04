#include <iostream>
using std::cout;

#include "Figura.h"
#include "Cuadrado.h"
#include "Triangulo.h"

#include <vector>
using std::vector;

int main()
{
	Cuadrado c(10);
	Triangulo t(20, 10);

	c.queSoy();
	cout << '\n';
	c.dibujar();

	cout << "\n\n";

	t.queSoy();
	cout << '\n';
	t.dibujar();

	cout << "\n\n\n";

	vector<Figura*> figuras(4);

	figuras[0] = new Cuadrado(19);
	figuras[1] = new Cuadrado(5);
	figuras[2] = new Triangulo(20, 10);
	figuras[3] = new Triangulo(30, 15);
	figuras.push_back(new Triangulo(10, 5));	// al pasar el tamaño del vector este se duplica ahora seria 8

	for (int i = 0; i < figuras.size(); i++)
	{
		figuras[i]->queSoy();
		cout << '\n';
		figuras[i]->dibujar();
		cout << "\n\n";
	}

	for (int j = 0; j < figuras.size(); j++)
		delete figuras[j];

	return 0;
}
