// definiciones de las funciones miembro para la clase Tiempo
#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Tiempo.h"

// constructor
Tiempo::Tiempo(int h, int m, int s)
{
    establecerTiempo(h, m, s);
}

// establece el tiempo h m s usando las funciones "establecer"
void Tiempo::establecerTiempo(int h, int m, int s)
{
    establecerHora(h);
    establecerMinuto(m);
    establecerSegundo(s);
}

// establece la hora
void Tiempo::establecerHora(int h)
{
    hora = (h >= 0 && h < 24) ? h : 0;
}

// establece los minutos
void Tiempo::establecerMinuto(int m)
{
    minuto = (m >= 0 && m <= 59) ? m : 0;
}

// establecer los segundos
void Tiempo::establecerSegundo(int s)
{
    segundo = (s >= 0 && s <= 59) ? s : 0;
}

// retorna la hora
int Tiempo::obtenerHora()
{
    return hora;
}

// retorna los minutos
int Tiempo::obtenerMinuto()
{
    return minuto;
}

// retorna los segundos
int Tiempo::obtenerSegundo()
{
    return segundo;
}

// imprime la hora en formato universal (HH:MM:SS)
void Tiempo::imprimirUniversal()
{
    cout << setfill('0') << setw(2) << obtenerHora() << ":"
        << setw(2) << obtenerMinuto() << ":" << setw(2) << obtenerSegundo() << "\n";
}


// imprime la hora en formato estandar (HH:MM:SS AM or PM)
void Tiempo::imprimirEstandar()
{
    cout << ((obtenerHora() == 0 || obtenerHora() == 12) ? 12 : obtenerHora() % 12) << ":"
        << setfill('0') << setw(2) << obtenerMinuto() << ":" << setw(2) << obtenerSegundo()
        << ((obtenerHora() < 12) ? " AM" : " PM") << "\n";
}
