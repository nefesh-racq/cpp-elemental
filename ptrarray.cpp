// aritmetica de punteros recorrido de un array
// array++ es igual a "array + 1 * (tamaño del tipo de array)"
// ejemplo int *ptr = array, si hacemos operacion de punteros ++
// seria ptr++ = a ptr + 1 * 4 := avanzaria 4 bytes en el arreglo
// lo cual seria la segunda posicion
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	char cad[] = "abcdefghij";
	int *ptr = array;
	char *cPtr = cad;

	// usamos el puntero para avanzar en el array
	for (int i = 0; i < 10; i++)
	{
		cout << *ptr << " ";
		ptr++;	// avanza a la sgte posicion del arregloptr + 1 * (int)
	}

	cout << endl;

	// recorremos el array o cadena cad con un puntero
	while (*cPtr != '\0')
	{
		cout << *cPtr << " ";
		cPtr++;	// avanza a la sgte posicion de la cadena
	}

	cout << "\narray : " << array;
	cout << "\ncadena : " << cad << endl;

	// tambien se puede usar el puntero  con corchees oh sumandole un
	// nro para apuntar a un elemento del array
	ptr = array;	// volvemos a poner el ptr en el inicio del array
	cout << "   *(ptr + 3) = " << *(ptr + 3)
		<< "\n    *ptr + 3 = " << *ptr + 3
		<< "\n  *array + 3 = " << *array + 3
		<< "\n    array[3] = " << array[3]
		<< "\n*(array + 3) = " << *(array + 3)
		<< "\n      ptr[3] = " << ptr[3] 
		<< "\n         ptr = " << ptr
		<< "\n       array = " << array
		<< "\n        *ptr = " << *ptr
		<< "\n      *array = " << *array
		<< "\n        &ptr = " << &ptr
		<< "\n      &array = " << &array
		<< "\n   &array[3] = " << &array[3]
		<< "\n   array + 3 = " << array + 3 << endl;

	return 0;
}

