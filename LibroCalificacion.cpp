#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;

class LibroCalificaciones
{
private:
   string nombre;

public:
   LibroCalificaciones(string nom) 
   {
      nombre = nom;
   }

   void mostrarMensaje()
   {
      cout << "bien venido al libro de calificaciones " << nombre << endl;
   }

   void mostrarMensaje(string nom)
   {
      cout << "bien venido a " << nom << endl;
   }
};

int main()
{
   LibroCalificaciones lc("nombre libro");

   lc.mostrarMensaje();

   string nombre;

   cout << "ingrese el nombre del colegio ";
   getline(cin, nombre);
   cout << endl;

   lc.mostrarMensaje(nombre);

   return 0;
}

