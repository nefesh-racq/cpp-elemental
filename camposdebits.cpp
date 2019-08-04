// 
struct BitCarta
{
	unsigned cara : 4;
	unsigned palo : 2;
	unsigned color : 1;
};

// definicion de la clase mazodecartas
class MazoDeCartas
{
public:
	MazoDeCartas();
	void repartir();

private:
	BitCarta mazo[52];
};

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

MazoDeCartas::MazoDeCartas()
{
	for (int i = 0; i <= 51; i++)
	{
		mazo[i].cara = i % 13;	// caras en orden
		mazo[i].palo = i / 13;	// palos en orden
		mazo[i].color = i / 26;	// colores en orden
	}
}

// reparte las cartas en el mazo
void MazoDeCartas::repartir()
{
	for (int k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++)
		cout << "Carta:" << setw(3) << mazo[k1].cara 
			<< "   Palo:" << setw(2) << mazo[k1].palo 
			<< "   Color:" << setw(2) << mazo[k1].color 
			<< "   " << "Carta:" << setw(2) << mazo[k2].cara 
			<< "   Palo:" << setw(2) << mazo[k2].palo 
			<< "   Color:" << setw(2) << mazo[k2].color
			<< endl;
}

int main()
{
	MazoDeCartas mazo;

	mazo.repartir();

	return 0;
}

struct Ejemplo
{
	unsigned a : 13;
	unsigned : 3;
	unsigned b : 4;
};

structu Ejemplo
{
	unsigned a : 13;
	unsigned   : 0;
	unsigned b : 4;
};