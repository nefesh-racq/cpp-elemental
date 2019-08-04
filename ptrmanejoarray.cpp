// uso de notaciones de subindice y apuntadores con arreglos
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	int b[] = {10, 20, 30, 40};
	int *bPtr = b;	// establece bPtr para apuntar al arreglo b

	// imprime el arreglo usando la notacion de subindic de arreglo
	cout << "Se imprime el arreglo b con:\nnotacion de subindice de arreglo\n";

	for (int i = 0; i < 4; i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	// imprime el arreglo b usando el nombre del arreglo y la notacion
	// apuntador/desplazamiento
	cout << "\nNotacion apuntador/desplazamiento\ndonde el apuntador"
		<< "es el nombre del arreglo\n";

	for (int j = 0; j < 4; j++)
		cout << "*(b + " << j << ") = " << *(b + j) << endl;

	// imprime arreglo b usando bPtr y la notacion de subindice de arreglo
	cout << "\nNotacion de subindice de apuntador\n";

	for (int k = 0; k < 4; k++)
		cout << "bPtr[" << k << "] = " << bPtr[k] << endl;

	cout << "\nNotacion apuntador/desplazamiento\n";

	for (int l = 0; l < 4; l++)
		cout << "*(bPtr + " << l << ") = " << *(bPtr + l) << endl;

	return 0;
}

