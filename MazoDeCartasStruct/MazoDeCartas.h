// representacion de un mazo de cartas para el juego

#ifndef MAZODECARTAS_H
#define MAZODECARTAS_H

// estructura Carta
struct Carta
{
	const char *cara;
	const char *palo;
};

// clase mazo de cartas
class MazoDeCartas
{
public:
	MazoDeCartas();
	void barajar();
	void repartir() const;

private:
	Carta mazo[52];
};

#endif//MAZODECARTAS_H