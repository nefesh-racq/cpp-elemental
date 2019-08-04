// uso de strcat y strncat
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>	// prototipos para strcat y strncat
using std::strcat;
using std::strncat;

int main()
{
	char s1[20] = "feliz ";
	char s2[] = "Año nuevo ";
	char s3[40] = "";

	cout << "s1 = " << s1 << "\ns2 = " << s2;

	strcat(s1, s2);	// concatena s2 con s1 (longitud 16)

	cout << "\n\nDespues de strcat(s1, s2):\ns1 = " << s1
		<< "\ns2 = " << s2;

	// concatenamos los primeros 6 caracteres de s1 con s3;
	strncat(s3, s1, 6);	// coloca '\0' despues del ultimo caracter

	cout << "\n\nDespues de strncat(s3, s1, 6):\ns1 = " << s1
		<< "\ns3 = " << s3;

	strcat(s3, s1);	// concatenamos s1 con s3
	cout << "\n\nDespues de strcat(s3, s1):\ns1 = " << s1
		<< "\ns3 = " << s3 << endl;

	return 0;
}

