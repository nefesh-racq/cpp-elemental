// definicion de la clase persona
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string;

class Persona
{
public:
	Persona();
	Persona(string, int);
	void setNombre(char []);
	void setEdad(int);
	void presentarse();

private:
	string nombre;
	int edad;
};

#endif // PERSONA_H
