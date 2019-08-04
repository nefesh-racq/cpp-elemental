// ejemplo sobre alcance de una variable
#include <iostream>

using std::cout;
using std::endl;

void usarLocal();   // prototipo de funcion
void usarLocalStatic();  //
void usarGlobal();

int x = 1;   // variable global

int main() {
  cout << "la x global en main es " << x << endl;

  int x = 5;

  cout << "la x local en el alcance exterior de main es " << x << endl;

  {  // empieza un nuevo alcance
    int x = 8;  // oculta la x en el alcance esterior y la x global

    cout << "la x local en el alcance interior de main es " << x << endl;
  }  // termina el nuevo alcance

  cout << "\nla x local en el alcance exterior de main es " << x << endl;

  usarLocal();  // tiene la x local
  usarLocalStatic();  // tiene la x local estatica
  usarGlobal();   // usa la x global
  usarLocal();  // reinicia su x local
  usarLocalStatic();  // la x local estatica retiene su valor
  usarGlobal();   // la x global tambien retiene su valor anterior

  cout << "la x local en main es " << x << endl;
  
  return 0;
}

void usarLocal() {
  int x = 25;   // inicializa cada vez que se llama a la funcion

  cout << "\nla x local es " << x << ", al entrar a usarLocal()" << endl;
  x++;
  cout << "la x local es " << x << ", al salir de usarLocal()" << endl;
}

void usarLocalStatic() {
  static int x = 40;  // se inicializa la primera vez que se llama a la funcion

  cout << "\nla x local estatica es " << x << ", al entrar a usarLocalStatic()" << endl;
  x++;
  cout << "la x local estatica es " << x << ", al salir de usarLocalStatic()" << endl;
}

void usarGlobal() {
  cout << "\nla x global  es " << x << ", al entrar a usarGlobal()" << endl;
  x*= 10;
  cout << "la x global es " << x << ", al entrar a usarGlobal()" << endl;
}
