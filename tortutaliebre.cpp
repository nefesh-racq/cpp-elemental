// simula una carrera de la tortuga y liebre
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include <iomanip>
using std::setw;

int main()
{
	int const PASOS = 70;
	int iTortuga = 1;
	int iLiebre = 1;
	int movTortuga = 0;
	int movLiebre = 0;
	srand(time(NULL));	

	cout << "PUM!!!!\nY ARRANCAN!!!\n";

	while (iTortuga <= PASOS && iLiebre <= PASOS) {
		int porcentaje = 1 + rand() % 11;

		// movimiento tortuga
		if (1 <= porcentaje && porcentaje <= 5)
		{
			movTortuga = 3;		// paso pesado rapido
			//cout << "paso pesado rapido  ";
		}
		else if (6 <= porcentaje && porcentaje <= 7)
		{
			movTortuga = -6;	// resbalón
			//cout << "resbalón  ";
		}
		else if (8 <= porcentaje && porcentaje <= 10)
		{
			movTortuga = 1;		// paso pesado lento
			//cout << "paso pesado lento  ";
		}

		iTortuga += movTortuga;

		if (iTortuga < 1)
			iTortuga = 1;

		cout << "T : pos " << setw(2) << iTortuga;

		porcentaje = 1 + rand() % 11;

		// movimiento liebre
		if (1 <= porcentaje && porcentaje <= 2)
		{
			movLiebre = 0;		// dormir
			//cout << "dormir  ";
		}
		else if (3 <= porcentaje && porcentaje <= 4)
		{
			movLiebre = 9;		// gran salto
			//cout << "gran salto  ";
		}
		else if (5 == porcentaje)
		{
			movLiebre = -12;	// gran resbalón
			//cout << "gran resbalón  ";
		}
		else if (6 <= porcentaje && porcentaje <= 8)
		{
			movLiebre = 1;		// pequeño salto
			//cout << "pequeño salto  ";
		}
		else if (9 <= porcentaje && porcentaje <= 10)
		{
			movLiebre = -2;		// pequeño resbalón
			//cout << "pequeño resbalón  ";
		}

		iLiebre += movLiebre;
		
		if (iLiebre < 1)
			iLiebre = 1;

		cout << setw(15) << "H : pos " << setw(2) << iLiebre;

		// comparamos si estan en el mismo lugar si es asi la tortuga muerde a la liebre
		if (iTortuga == iLiebre)
			cout << "  OUCH!";

		cout << "\n";
	}

	if (iTortuga == iLiebre)
		cout << "\nEs un empate.\n";
	else if (iTortuga > iLiebre)
		cout << "\nLA TORTUGA GANA!!!! YAY!!!!\n";
	else
		cout << "\nla liebre gana. Que mal\n";

	return 0;
}

