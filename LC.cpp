#include <iostream>
#include <string>

#include "LC.h"

using std::cout;
using std::endl;

LC::LC(string nom)
{
   setNombre(nom);
}

void LC::setNombre(string nom) {
   if (nom.length() <= 25)
      nombre = nom;

   if (nom.length() > 25) {
      nombre = nom.substr(0, 25);
      cout << "el nombre exede la cantidad de caracteres" << endl;
   }
}

void LC::getNombre() const {
   cout << "" << nombre << endl;
}

