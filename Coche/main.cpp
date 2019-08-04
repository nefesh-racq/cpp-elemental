#include "Coche.h"

int main()
{
	// cuando el parametro es string se puede pasar la cadena directo como argumento
	// no se podria eso si el parametro fuera de tipo char[] o char*
	Coche c("ford", "suv", 1999);
	Coche *cPtr;

	cPtr = &c;		// apuntamos el puntero a c
	cPtr->verDetalle();

	Coche *cochePtr = new Coche("toyota", "hatchback", 2001);

	cochePtr->verDetalle();

	return 0;
}

