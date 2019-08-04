// clase constructor que contiene un constructor con argumentos
// predefinidos

// evita multiples inclusiones del archivo de cabecera
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
    Tiempo(int = 0, int = 0, int = 0);  // constructor con valores predefinidos

    // funciones "establecer"
    void establecerTiempo(int, int, int);   // hora, minuto, segundo
    void establecerHora(int);               // establece la hora
    void establecerMinuto(int);             // establece los minutos
    void establecerSegundo(int);            // establece los segundos
    // funciones "obtener"
    int obtenerHora();
    int obtenerMinuto();
    int obtenerSegundo();
    // funciones "imprimir"
    void imprimirUniversal();
    void imprimirEstandar();

private:
    int hora;       // 0 - 23
    int minuto;     // 0 - 59
    int segundo;    // 0 - 59
};

#endif // TIEMPO_H
