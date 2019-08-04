#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

struct empleado
{
	unsigned int id;
	string nombre;
	double salario;
	unsigned int edad;
}pepe;

int main(int argc, char const *argv[])
{
	empleado jose = {10, "jose jose", 150.00, 25};

	cout << jose.id << "\n" << jose.nombre << endl;

	pepe.id = 11;
	pepe.nombre = "pepe";
	pepe.salario = 545.00;
	pepe.edad = 32;

	cout << pepe.id << "\n" << pepe.nombre << endl;

	return 0;
}