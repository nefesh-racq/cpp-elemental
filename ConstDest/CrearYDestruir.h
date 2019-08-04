// clase crear y destruir demuestra la creacion y destruccion de objetos
#include <string>
using std::string;

#ifndef CREAR_H
#define CREAR_H

class CrearYDestruir
{
public:
    CrearYDestruir(int, string);    // constructor
    ~CrearYDestruir();              // destructor

private:
    int idObjeto;       // id para el objeto
    string mensaje;     // mensaje que describe al objeto
};

#endif // CREAR_H
