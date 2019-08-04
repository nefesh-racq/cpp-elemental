#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <vector>
using std::vector;

#include <iomanip>
using std::setw;

void imprimirVector(const vector<int> &);
void recibirVector(vector<int> &);	// introduce los valores en el vector

int main()
{
	vector<int> enteros1(7);
	vector<int> enteros2(10);

	// imprime tamaño y contenido de enteros1
	cout << "El tamaño y el contenido de enteros1 es : " << enteros1.size()
		<< "\nvector enteros1 despues de la inicializacion " << endl;
	imprimirVector(enteros1);

	// imprime el tamaño y contenido de enteros2
	cout << "El tamaño y contenido de enteros2 es : " << enteros2.size()
		<< "\nvector enteros2 despues de la inicializacion " << endl;
	imprimirVector(enteros2);

	// recibe e imprime enteros1 y enteros2
	cout << "\nEscriba 17 enteros: " << endl;
	recibirVector(enteros1);
	recibirVector(enteros2);

	cout << "\nDespues de la entrada, los vectores contienen " << endl
		<< "enteros1: " << endl;
	imprimirVector(enteros1);
	cout << "enteros2: " << endl;
	imprimirVector(enteros2);

	// usa el operador de desigualdad != con objetos de tipo vector
	cout << "\nEvaluacion: enteros1 != enteros2" << endl;

	if (enteros1 != enteros2)
		cout << "enteros1 y enteros2 no son iguales " << endl;

	// crea el vector enteros3 usando enteros1
	vector<int> enteros3(enteros1);	// usa su constructor de copia

	// imprime el tamaño y contenido de enteros3
	cout << "ņEl tamaño y contenido de enteros3 es : " << enteros3.size()
		<< "\nvector enteros3 despues de la inicializacion " << endl;
	imprimirVector(enteros3);

	// usa el operador de asignacion = con objetos de tipo vector
	cout << "\nAsignacion de entero2 a enteros1" << endl;
	enteros1 = enteros2;	// asigna enteros2 a enteros1 usando sobrecarga de operadores

	cout << "enteros1: " << endl;
	imprimirVector(enteros1);
	cout << "enteros2: " << endl;
	imprimirVector(enteros2);

	// usa el operador de igualdad == con objetos de tipo vector
	cout << "\nEvalucacion: enteros1 == enteros2: " << endl;

	if (enteros1 == enteros2)
		cout << "enteros1 y enteros2 son iguales " << endl;

	// usa corchetes para crear rvalue
	cout << "\nenteros1[5] es " << enteros1[5] << endl;

	// usa corchetes para crear lvalue
	cout << "asignacion de 1000 a enteros1[5] " << endl;
	enteros1[5] = 1000;
	cout << "enteros1: " << endl;
	imprimirVector(enteros1);

	// intenta usar subindice fuera de rango
	cout << "\nIntento de asignar 1000 a enteros1.at(15)" << endl;
	enteros1.at(15) = 1000;	// error: fuera de rango

	return 0;
}

// imprime el contenido del vector
void imprimirVector(const vector<int> &arreglo)
{
	size_t i;	// declara la variable de control

	for (i = 0; i < arreglo.size(); i++)
	{
		cout << setw(12) << arreglo[i];

		if ((i + 1) % 4 == 0)	// 4 numeros por fila de resultados
			cout << endl;
	}	// fin de for

	if (i % 4 != 0)
		cout << endl;
}

// recibe el contenido del vector
void recibirVector(vector<int> &arreglo)
{
	for (size_t i = 0; i < arreglo.size(); i++)
		cin >> arreglo[i];
}

