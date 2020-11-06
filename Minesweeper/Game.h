#ifndef GAME
#define GAME

#include "Field.h"

class Game : public Field
{
private:
	int x;
	int y;
	int Place_not_bomb;
	int counter;
	bool** isOpen;
public:
	Game();
	Game(int a);

	void ShowNextCell();
	bool isLost(int i, int j);
	bool isBomb(int x, int y);
	bool isWin();
	void game();
	void restart(sf::RenderWindow& app);
};
#endif