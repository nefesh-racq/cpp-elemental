// ejemplo de recursividad indirecta
#include <iostream>
using std::cout;
using std::endl;

void funcionA(char);
void funcionB(char);

int main()
{
	cout << "Alfabeto: ";
	funcionA('Z');
	cout << endl;

	return 0;
}

void funcionA(char c)
{
	if (c > 'A')
		funcionB(c);

	cout << c << " ";
}

void funcionB(char c)
{
	funcionA(--c);
}
