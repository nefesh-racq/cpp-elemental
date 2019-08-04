#include <iostream>
using std::endl;
using std::cout;

void iniStaticArray(void);
void iniAutomaticArray(void);

int main() {
	cout << "PRIMERA LLAMADA A LAS FUNCIONES..\n";
	iniStaticArray();
	iniAutomaticArray();

	cout << "\n\nSEGUNDA LLAMADA A LAS FUNCIONES.." << endl;
	iniStaticArray();
	iniAutomaticArray();
	cout << endl;

	return 0;
}


void iniStaticArray(void) {
	// inicializa el arreglo con 0 la primera vez
	static int arreglo1[3];	// arreglo local static

	cout << "\nvalores al entrar en iniStaticArray()\n";

	// imprimimos el contenido
	for (int i = 0; i < 3; i++)
		cout << "arreglo1[" << i << "]=" <<  arreglo1[i] << endl;

	cout << "\nvalores al salir de iniStaticArray()\n";

	// inicializamos el arreglo con otros valores e imprimimos
	for(int j = 0; j < 3; j++)
		cout << "arreglo1[" << j << "] = " << (arreglo1[j] += 5) << endl;
}

void iniAutomaticArray(void) {
	// inicializamos los elementos cada vez que se llama ala funcion
	int arreglo2[3] = {1, 2, 3};

	cout << "\n\nvalores al entrar en iniAutomaticArray() \n";

	// imprimimos el arreglo2
	for (int i = 0; i < 3; i++)
		cout << "arreglo2[" << i << "]= " << arreglo2[i] << endl;

	cout << "\nvalores al salir de iniAutomaticArray()\n";

	// modifica el contenido del arreglo2 y lo imprime
	for (int j = 0; j < 3; j++)
		cout << "arreglo2[" << j << "]= " << (arreglo2[j] += 3) << endl;
}
