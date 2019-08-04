#include <iostream>
using std::endl;
using std::cout;

#include <iomanip>
using std::setw;

void imprimir(const int[][3]);

int main()
{
	int a1[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int a2[2][3] = {1, 2, 3, 4, 5};
	int a3[2][3] = {{1, 2}, {4}};

	cout << "a1[2][3] = {{1, 2, 3}, {4, 5, 6}}" << endl;
	imprimir(a1);

	cout << "\na2[2][3] = {1, 2, 3, 4, 5}" << endl;
	imprimir(a2);

	cout << "\na3[2][3] = {{1, 2}, {4}}" << endl;
	imprimir(a3);

	return 0;
}

void imprimir(const int array[][3])
{
	// recore las filas del arreglo
	for (int fil = 0; fil < 2; fil++)
	{
		// recore las columnas del arreglo
		for (int col = 0; col < 3; col++)
			cout << setw(2) << array[fil][col];

		cout << endl;
	}
}

