#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
    Tiempo(int = 0, int = 0, int = 0);
    // funciones set
    void setTiempo(int, int, int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);

    // funciones get
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;

    // funciones imprimir
    void imprimirUniversal() const;
    void imprimirEstandar() const;

private:
    int hora;
    int minuto;
    int segundo;
};

#endif // TIEMPO_H

// definicion de la clase tiempo
#include <iomanip>
using std::setfill;
using std::setw;

#include <iostream>
using std::cout;
using std::endl;


// constructor
Tiempo::Tiempo(int hora, int minuto, int segundo)
{
    setTiempo(hora, minuto, segundo);
}

void Tiempo::setTiempo(int hora, int minuto, int segundo)
{
    setHora(hora);
    setMinuto(minuto);
    setSegundo(segundo);
}

//
void Tiempo::setHora(int h)
{
    hora = (0 <= h && h < 24) ? h : 0;
}

//
void Tiempo::setMinuto(int m)
{
    minuto = (0 <= m && m < 60) ? m : 0;
}

//
void Tiempo::setSegundo(int s)
{
    segundo = (0 <= s && s < 60) ? s : 0;
}

//
int Tiempo::getHora() const
{
    return segundo;
}

//
int Tiempo::getMinuto() const
{
    return minuto;
}

//
int Tiempo::getSegundo() const
{
    return segundo;
}

// HH:MM:SS
void Tiempo::imprimirUniversal() const
{
    cout << setfill('0') << setw(2) << getHora() << ":"
        << setw(2) << getMinuto() << ":" << getSegundo() << endl;
}

// HH:MM:SS AM o PM
void Tiempo::imprimirEstandar() const
{
    cout << ((getHora() == 0 || getHora() == 12) ? 12 : getHora() % 12)
        << ":" << setfill('0') << setw(2) << getMinuto()
        << "::" << setw(2) << getSegundo() << (getHora() < 12 ? " AM" : " PM")
        << endl;
}

// funcion main para manejar el tiempo
// el objeto constante no puede hacer llamadas a sus funciones que
// no sean constantes
int main()
{
    Tiempo despertar(6, 35, 0);         // objeto no constante
    const Tiempo mediodia(12, 0, 0);    // objeto constante

                                    // OBJETO       FUNCION MIEMBRO
    despertar.setHora(18);          // no const     no const
    mediodia.setHora(12);           // const        no const

    despertar.getHora();            // no const     const
    mediodia.getMinuto();           // const        const
    mediodia.imprimirUniversal();   // const        const
    mediodia.imprimirEstandar();    // const        no const

    return 0;
}
