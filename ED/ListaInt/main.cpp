#include "Lista.h"

int main()
{
	Lista li;
	int entero;

	for (int i = 1; i < 10; i++)
	{
		entero = 3 * i - 1;
		li.insertarAlFinal(entero);
	}

	li.imprimir();
	
	return 0;
}