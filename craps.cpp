#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>   // contiene los prototipos para srand y rand
using std::rand;
using std::srand;

#include <ctime>   // contiene prototipos para time
using std::time;

int tirarDados();   // tira los dados, calculo y muestra el resultado

int main() {
  enum Estado {CONTINUAR, GANO, PERDIO};   // constantes

  int miPunto;   // punto si no gana o pierde el el primer tiro
  Estado estadoJuego;  // puede contener constantes definadas con enum Estado
  // genera la semilla para nros aleatorios
  srand(time(0));

  int sumaDeDados = tirarDados();   // primer tiro de dados

  // determina el estado del juego
  switch (sumaDeDados) {
    case 7:   // gana con 7 o 11 en el primer tiro
    case 11:
      estadoJuego = GANO;
      break;
      
    case 2:   // pierde con 2 o 3 o 12 en el primer tiro
    case 3:
    case 12:
      estadoJuego = PERDIO;
      break;

    default:   // no gano ni perdio
      estadoJuego = CONTINUAR;   // el juegue continua
      miPunto = sumaDeDados;     // recuerda los puntos

      cout << "El punto es " << miPunto << endl;
  }

  // mientras el juego no este completo
  while (estadoJuego == CONTINUAR) {
    sumaDeDados = tirarDados();   // tira los dados

    // comprobar el estado del juego
    if (sumaDeDados == miPunto) // gana al hacer un punto
      estadoJuego = GANO;
    else
      if (sumaDeDados == 7)
	estadoJuego = PERDIO;
  }

  // muestra mensaje de gano o no gano
  if (estadoJuego == GANO)
    cout << "el jugador gano " << endl;
  else
    cout << "el jugador perdio" << endl;

  return 0;
}

int tirarDados() {
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6;  // primer tiro del dado
  int dado2 = 1 + rand() % 6;  // segundo tiro del dado

  int suma = dado1 + dado2;  // calcula la suma

  // muestra los resultados de este tiro
  cout << "el jugador tiro " << dado1 << " + " << dado2 << " = " << suma << endl;

  return suma;  // retorna la suma
}


