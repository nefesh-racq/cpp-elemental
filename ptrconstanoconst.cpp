// intento de modiicar un apuntador constante a datos no constantes

int main()
{
	int x, y;

	// ptr es un apuntador constante a un entero que se puede modificar
	// a través de un ptr, pero ptr siempre apunta a la misma
	// direccion de memoria
	int *const ptr = &x;

	*ptr = 7;	// se permite: *ptr no es const
	ptr = &y;	// error: ptr es const; no se puede asignar a una nueva direccion

/*
	const int *ptr = &x;

	ptr = &y;
*/
	return 0;
}

