#include "MyApp.h"

int main()
{
	MyApp *game = new MyApp();

	game->play();
	delete game;

	return 0;
}