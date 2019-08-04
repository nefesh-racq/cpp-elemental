// clase Tiempo
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
    Tiempo(int = 0, int = 0, int = 0);
    void establecerTiempo(int, int, int);
    int obtenerHora();
    int &establecerHoraIncorrecta(int);  // devuelve uan referencia a un entero es PELIGROSA

private:
    int hora;
    int minuto;
    int segundo;
};

#endif // TIEMPO_H
