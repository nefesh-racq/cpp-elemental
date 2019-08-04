// torres de hanoi recursividad
#include <iostream>
using std::cout;
using std::endl;

void hanoi(char, char, char, int);

int main()
{
	cout << "TORRES DE HANOI.\n";
	hanoi('A', 'B', 'C', 3);

	return 0;
}

/*
void hanoi(char varinicial, char varcentral, char varfinal, int n)
{
	if (n == 1)
		cout << "Mover disco " << n << " desde varilla "
			<< varinicial << " a varilla " << varfinal
			<< endl;
	else
	{
		hanoi(varinicial, varfinal, varcentral, n - 1);
		cout << "Mover disco " << n << " desde varilla "
			<< varinicial << " a varilla " << varfinal
			<< endl;
		hanoi(varcentral, varinicial, varfinal, n - 1);
	}
}
*/
void hanoi(char inicio, char centro, char final, int disco)
{
	if (disco == 1)
		cout << "Mover disco " << disco << " de " << inicio
			<< " a " << final << endl;
	else
	{
		hanoi(inicio, final, centro, disco - 1);
		cout << "Mover disco " << disco << " de " << inicio
			<< " a " << final << endl;
		hanoi(centro, inicio, final, disco - 1);
	}
}
