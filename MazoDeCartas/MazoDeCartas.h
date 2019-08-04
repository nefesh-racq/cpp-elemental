//representa un mazo de cartas de juego
class MazoDeCartas
{
public:
	MazoDeCartas();		// inicializa em mazo
	void barajar();		// baraja las cartas en el mazo
	void repartir();	// reparte las cartas del mazo

private:
	int mazo[4][13];	// representa el mazo de cartas
};

