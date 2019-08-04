#include "Lista.h"

int main()
{
	Lista<int> li;
	int entero;

	for (int i = 1; i < 10; i++)
	{
		entero = 2 * i;
		li.insertarFinal(entero);
	}

	li.imprimir();

	return 0;
}