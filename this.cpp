// llamada en cascada a funcioens miembro usando el apuntador this
// class tiempo
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
	Tiempo(int = 0, int = 0, int = 0);

	// funciones set el retorno de una referencia permite las llamadas en cascada
	// retornando el puntero this
	Tiempo &setTiempo(int, int, int);	// hora, minuto, segundo
	Tiempo &setHora(int);				//
	Tiempo &setMinuto(int);
	Tiempo &setSegundo(int);

	// funciones get
	int getHora() const;
	int getMinuto() const;
	int getSegundo() const;

	// funciones de impresion
	void imprimirUniversal() const;	// HH:MM:SS
	void imprimirEstandar() const;	// HH:MM:SS AM o PMsss

private:
	int hora;		// 0 - 23
	int minuto;		// 0 - 59
	int segundo;	// 0 - 59
};

#endif // TIEMPO_H

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

Tiempo::Tiempo(int hr, int min, int seg)
{
	setTiempo(hr, min, seg);
}

Tiempo &Tiempo::setTiempo(int h, int m, int s)
{
	setHora(h);
	setMinuto(m);
	setSegundo(s);

	return *this;
}

Tiempo &Tiempo::setHora(int h)
{
	hora = (0 <= h && h < 24) ? h : 0;

	return *this;
}

Tiempo &Tiempo::setMinuto(int m)
{
	minuto = (0 <= m && m < 60) ? m : 0;

	return *this;
}

Tiempo &Tiempo::setSegundo(int s)
{
	segundo = (0 <= s && s < 60) ? s : 0;

	return *this;
}

int Tiempo::getHora() const
{
	return hora;
}

int Tiempo::getMinuto() const
{
	return minuto;
}

int Tiempo::getSegundo() const
{
	return segundo;
}

void Tiempo::imprimirUniversal() const
{
	cout << setfill('0') << setw(2) << hora << ":"
		<< setw(2) << minuto << ":" << setw(2) << segundo;
}

void Tiempo::imprimirEstandar() const
{
	cout << ((hora == 0 || hora == 12) ? 12 : hora % 12)
		<< ":" << setfill('0') << setw(2) << minuto
		<< ":" << setw(2) << segundo << (hora < 12 ? "AM" : "PM");
}

int main()
{
	Tiempo t;

	// llamada en cascada a las funciones
	t.setHora(18).setMinuto(49).setSegundo(23);

	// imprime el tiempo
	cout << "Tiempo universal: ";
	t.imprimirUniversal();

	cout << "\nTiempo estandar: ";
	t.imprimirEstandar();

	cout << "\n\nNuevo tiempo estandar: ";

	// llamadas en cascada a funciones
	t.setTiempo(20, 20, 20).imprimirEstandar();
	cout << endl;

	return 0;
}

