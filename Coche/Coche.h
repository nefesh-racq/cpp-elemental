#ifndef COCHE_H
#define COCHE_H

#include <string>
using std::string;

class Coche
{
public:
	Coche(string, string, int);
	void verDetalle();

private:
	string marca;
	string modelo;
	int anio;
};

#endif // COCHE_H
