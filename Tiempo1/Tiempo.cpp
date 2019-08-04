// definicion de la clase TIEMPO
#include "Tiempo.h"

// constructor
Tiempo::Tiempo(int hr, int min, int seg)
{
    establecerTiempo(hr, min, seg);
}

// establece el tiempo de horas min, segundo
void Tiempo::establecerTiempo(int h, int m, int s)
{
    hora = ( h >= 0 && h < 24 ) ? h : 0; // valida la hora
    minuto = ( m >= 0 && m < 60 ) ? m : 0; // valida el minuto
    segundo = ( s >= 0 && s < 60 ) ? s : 0; // valida el segundo
}

// obtiene el tiempo
int Tiempo::obtenerHora()
{
    return hora;
}

// MALA PRACTICA DE PROGRAMACION:
// devolver una referencia a un miembro dato privado
int &Tiempo::establecerHoraIncorrecta(int h)
{
    hora = (h >= 0 && h < 24) ? h : 0;

    return hora;
}
