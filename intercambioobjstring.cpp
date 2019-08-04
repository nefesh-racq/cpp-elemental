// uso de la funcion swap para intercambiar dos objetos string
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string primero("uno");
	string segundo("dos");

	cout << "primero: " << primero
		<< "\nsegundo: " << segundo
		<< endl;
	primero.swap(segundo);

	cout << "primero.swap(segundo): " << primero << endl;

	return 0;
}
