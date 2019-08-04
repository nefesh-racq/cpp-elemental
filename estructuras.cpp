#include <iostream>
using std::cout;
using std::endl;

struct Carta
{
	const char *cara;
	const char *palo;
};

struct Ejemplo
{
	char c;
	int i;
} ejemplo1, ejemplo2;


class Uno
{
public:
	int dato;
};


void pasoPorVoR(Uno &obj)
{
	obj.dato = 10;
}

int main()
{
	Carta unaCarta = {"tres", "corazones"};

	cout << unaCarta.cara << " -de- " << unaCarta.palo
		<< endl;

	Uno uno;

	pasoPorVoR(uno);
	cout << uno.dato << endl;

	typedef Carta *cartaPtr;

	cartaPtr cartaPtr0;

	//cartaPtr0 = new Carta();

	cartaPtr0->cara = "cinco";
	cartaPtr0->palo = "trebol";
	cout << cartaPtr0->cara << " -de- " << cartaPtr0->palo
		<< endl;

	return 0;
}