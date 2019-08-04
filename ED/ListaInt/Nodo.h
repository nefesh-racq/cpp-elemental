#ifndef NODO_H
#define NODO_H

// definimos la clase Lista par apoder usarla en
// nodo y asi accede a sus datos private desde Lista
class Lista;

class Nodo
{
	friend class Lista;

public:
	Nodo();
	Nodo(int &);
	~Nodo();

private:
	int info;
	Nodo *sgtePtr;
};

#endif//NODO_H