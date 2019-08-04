#ifndef MYAPP_H
#define MYAPP_H

#include "ArbolBinario.h"

class MyApp
{
public:
	MyApp();
	~MyApp();

	void play();

private:
	ArbolBinario *arbolPtr;
	bool GAMEOVER;

	void message();
};

#endif//MYAPP_H
