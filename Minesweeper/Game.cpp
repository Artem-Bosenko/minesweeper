#include"Game.h"

using namespace sf;

int w = 32;

Game::Game() : Field()
{
	x = 0, y = 0, counter = 0;
	Place_not_bomb = (n * n) - bomb;
	isOpen = new bool* [n];
	for (int i = 0; i < n; i++)
		isOpen[i] = new bool[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			isOpen[i][j] = false;
		}
}
Game::Game(int a) : Field(a)
{
	n = a;
	x = 0, y = 0, counter = 0;
	Place_not_bomb = (n * n) - bomb;
	isOpen = new bool* [n];
	for (int i = 0; i < n; i++)
		isOpen[i] = new bool[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			isOpen[i][j] = false;
		}
}
bool Game::isLost(int i, int j)
{
	if (isBomb(i, j) == true)
	{
		for (int k = 0; k < n; k++)
			for (int d = 0; d < n; d++) {
				FieldView[k][d] = FieldLogic[k][d];
			}
		return true;
	}
	return false;
}
bool Game::isBomb(int x, int y)
{
	if (FieldView[x][y] == 9) return true;
	return false;
}
bool Game::isWin()
{
	if (Place_not_bomb == counter) return true;
	return false;
}
void Game::ShowNextCell()
{
	if (FieldView[0][0] == 0)
	{
		if (FieldView[0][1] != 9 && isOpen[0][1] == false) { FieldView[0][1] = FieldLogic[0][1]; isOpen[0][1] = true; counter++; }
		if (FieldView[1][0] != 9 && isOpen[1][0] == false) { FieldView[1][0] = FieldLogic[1][0]; isOpen[1][0] = true; counter++; }
		if (FieldView[1][1] != 9 && isOpen[1][1] == false) { FieldView[1][1] = FieldLogic[1][1]; isOpen[1][1] = true; counter++; }
	}
	if (FieldView[0][n - 1] == 0)
	{
		if (FieldView[0][n - 2] != 9 && isOpen[0][n - 2] == false) { FieldView[0][n - 2] = FieldLogic[0][n - 2]; isOpen[0][n - 2] = true; counter++; }
		if (FieldView[1][n - 1] != 9 && isOpen[1][n - 1] == false) { FieldView[1][n - 1] = FieldLogic[1][n - 1]; isOpen[1][n - 1] = true; counter++; }
		if (FieldView[1][n - 2] != 9 && isOpen[1][n - 2] == false) { FieldView[1][n - 2] = FieldLogic[1][n - 2]; isOpen[1][n - 2] = true; counter++; }
	}
	if (FieldView[n - 1][0] == 0)
	{
		if (FieldView[n - 2][0] != 9 && isOpen[n - 2][0] == false) { FieldView[n - 2][0] = FieldLogic[n - 2][0]; isOpen[n - 2][0] = true; counter++; }
		if (FieldView[n - 1][1] != 9 && isOpen[n - 1][1] == false) { FieldView[n - 1][1] = FieldLogic[n - 1][1]; isOpen[n - 1][1] = true; counter++; }
		if (FieldView[n - 2][1] != 9 && isOpen[n - 2][1] == false) { FieldView[n - 2][1] = FieldLogic[n - 2][1]; isOpen[n - 2][1] = true; counter++; }
	}
	if (FieldView[n - 1][n - 1] == 0)
	{
		if (FieldView[n - 1][n - 2] != 9 && isOpen[n - 1][n - 2] == false) { FieldView[n - 1][n - 2] = FieldLogic[n - 1][n - 2]; isOpen[n - 1][n - 2] = true; counter++; }
		if (FieldView[n - 2][n - 1] != 9 && isOpen[n - 2][n - 1] == false) { FieldView[n - 2][n - 1] = FieldLogic[n - 2][n - 1]; isOpen[n - 2][n - 1] = true; counter++; }
		if (FieldView[n - 2][n - 2] != 9 && isOpen[n - 2][n - 2] == false) { FieldView[n - 2][n - 2] = FieldLogic[n - 2][n - 2]; isOpen[n - 2][n - 2] = true; counter++; }
	}

	//линии
	if (FieldView[0][y] == 0 && x == 0 && y != 0 && y != n - 1)
	{
		if (FieldView[x][y + 1] != 9 && isOpen[x][y + 1] == false) { FieldView[x][y + 1] = FieldLogic[x][y + 1]; isOpen[x][y + 1] = true; counter++; }
		if (FieldView[x][y - 1] != 9 && isOpen[x][y - 1] == false) { FieldView[x][y - 1] = FieldLogic[x][y - 1]; isOpen[x][y - 1] = true; counter++; }
		if (FieldView[x + 1][y] != 9 && isOpen[x + 1][y] == false) { FieldView[x + 1][y] = FieldLogic[x + 1][y]; isOpen[x + 1][y] = true; counter++; }
		if (FieldView[x + 1][y - 1] != 9 && isOpen[x + 1][y - 1] == false) { FieldView[x + 1][y - 1] = FieldLogic[x + 1][y - 1]; isOpen[x + 1][y - 1] = true; counter++; }
		if (FieldView[x + 1][y + 1] != 9 && isOpen[x + 1][y + 1] == false) { FieldView[x + 1][y + 1] = FieldLogic[x + 1][y + 1]; isOpen[x + 1][y + 1] = true; counter++; }
	}
	if (FieldView[x][0] == 0 && y == 0 && x != 0 && x != n - 1)
	{
		if (FieldView[x + 1][y] != 9 && isOpen[x + 1][y] == false) { FieldView[x + 1][y] = FieldLogic[x + 1][y]; isOpen[x + 1][y] = true; counter++; }
		if (FieldView[x - 1][y] != 9 && isOpen[x - 1][y] == false) { FieldView[x - 1][y] = FieldLogic[x - 1][y]; isOpen[x - 1][y] = true; counter++; }
		if (FieldView[x][y + 1] != 9 && isOpen[x][y + 1] == false) { FieldView[x][y + 1] = FieldLogic[x][y + 1]; isOpen[x][y + 1] = true; counter++; }
		if (FieldView[x - 1][y + 1] != 9 && isOpen[x - 1][y + 1] == false) { FieldView[x - 1][y + 1] = FieldLogic[x - 1][y + 1]; isOpen[x - 1][y + 1] = true; counter++; }
		if (FieldView[x + 1][y + 1] != 9 && isOpen[x + 1][y + 1] == false) { FieldView[x + 1][y + 1] = FieldLogic[x + 1][y + 1]; isOpen[x + 1][y + 1] = true; counter++; }
	}
	if (FieldView[n - 1][y] == 0 && x == n - 1 && y != n - 1 && y != 0)
	{
		if (FieldView[x][y + 1] != 9 && isOpen[x][y + 1] == false) { FieldView[x][y + 1] = FieldLogic[x][y + 1]; isOpen[x][y + 1] = true; counter++; }
		if (FieldView[x][y - 1] != 9 && isOpen[x][y - 1] == false) { FieldView[x][y - 1] = FieldLogic[x][y - 1]; isOpen[x][y - 1] = true; counter++; }
		if (FieldView[x - 1][y] != 9 && isOpen[x - 1][y] == false) { FieldView[x - 1][y] = FieldLogic[x - 1][y]; isOpen[x - 1][y] = true; counter++; }
		if (FieldView[x - 1][y - 1] != 9 && isOpen[x - 1][y - 1] == false) { FieldView[x - 1][y - 1] = FieldLogic[x - 1][y - 1]; isOpen[x - 1][y - 1] = true; counter++; }
		if (FieldView[x - 1][y + 1] != 9 && isOpen[x - 1][y + 1] == false) { FieldView[x - 1][y + 1] = FieldLogic[x - 1][y + 1]; isOpen[x - 1][y + 1] = true; counter++; }
	}
	if (FieldView[x][n - 1] == 0 && y == n - 1 && x != 0 && x != n - 1)
	{
		if (FieldView[x + 1][y] != 9 && isOpen[x + 1][y] == false) { FieldView[x + 1][y] = FieldLogic[x + 1][y]; isOpen[x + 1][y] = true; counter++; }
		if (FieldView[x - 1][y] != 9 && isOpen[x - 1][y] == false) { FieldView[x - 1][y] = FieldLogic[x - 1][y]; isOpen[x - 1][y] = true; counter++; }
		if (FieldView[x][y - 1] != 9 && isOpen[x][y - 1] == false) { FieldView[x][y - 1] = FieldLogic[x][y - 1]; isOpen[x][y - 1] = true; counter++; }
		if (FieldView[x - 1][y - 1] != 9 && isOpen[x - 1][y - 1] == false) { FieldView[x - 1][y - 1] = FieldLogic[x - 1][y - 1]; isOpen[x - 1][y - 1] = true; counter++; }
		if (FieldView[x + 1][y - 1] != 9 && isOpen[x + 1][y - 1] == false) { FieldView[x + 1][y - 1] = FieldLogic[x + 1][y - 1]; isOpen[x + 1][y - 1] = true; counter++; }
	}

	else if (FieldView[x][y] == 0 && x != 0 && y != 0 && x != n - 1 && y != n - 1)
	{
		if (FieldView[x + 1][y] != 9 && isOpen[x + 1][y] == false) { FieldView[x + 1][y] = FieldLogic[x + 1][y]; isOpen[x + 1][y] = true; counter++; }
		if (FieldView[x - 1][y] != 9 && isOpen[x - 1][y] == false) { FieldView[x - 1][y] = FieldLogic[x - 1][y]; isOpen[x - 1][y] = true; counter++; }
		if (FieldView[x][y + 1] != 9 && isOpen[x][y + 1] == false) { FieldView[x][y + 1] = FieldLogic[x][y + 1]; isOpen[x][y + 1] = true; counter++; }
		if (FieldView[x][y - 1] != 9 && isOpen[x][y - 1] == false) { FieldView[x][y - 1] = FieldLogic[x][y - 1]; isOpen[x][y - 1] = true; counter++; }
		if (FieldView[x - 1][y + 1] != 9 && isOpen[x - 1][y + 1] == false) { FieldView[x - 1][y + 1] = FieldLogic[x - 1][y + 1]; isOpen[x - 1][y + 1] = true; counter++; }
		if (FieldView[x + 1][y + 1] != 9 && isOpen[x + 1][y + 1] == false) { FieldView[x + 1][y + 1] = FieldLogic[x + 1][y + 1]; isOpen[x + 1][y + 1] = true; counter++; }
		if (FieldView[x - 1][y - 1] != 9 && isOpen[x - 1][y - 1] == false) { FieldView[x - 1][y - 1] = FieldLogic[x - 1][y - 1]; isOpen[x - 1][y - 1] = true; counter++; }
		if (FieldView[x + 1][y - 1] != 9 && isOpen[x + 1][y - 1] == false) { FieldView[x + 1][y - 1] = FieldLogic[x + 1][y - 1]; isOpen[x + 1][y - 1] = true; counter++; }
	}
}
void Game::game()
{
	RenderWindow app(VideoMode(n * w, n * w), "MINESWEEPER");
	Texture t;
	t.loadFromFile("..\\saper.jpg");
	Sprite s(t);

	//Подсчет мин вокруг каждой кле
	calc_mine();

	Font font;
	font.loadFromFile("..\\CyrilicOld.ttf");
	Text text("", font, 3 * n);
	text.setStyle(Text::Bold | Text::Underlined);

	while (app.isOpen())
	{
		Vector2i pos = Mouse::getPosition(app);
		x = pos.x / w;
		y = pos.y / w;

		Clock clock;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				app.close();
			}
			//Была нажата кнопка мыши…?
			if (event.type == Event::MouseButtonPressed)
				//Если это - левая кнопка мыши, то открываем клетку
				if (event.key.code == Mouse::Left)
				{
					FieldView[x][y] = FieldLogic[x][y];
					if (isOpen[x][y] == false)
					{
						counter++;
						isOpen[x][y] = true;
					}
					ShowNextCell();
				}
			//Если это – правая кнопка мыши, то отображаем флажок
				else if (event.key.code == Mouse::Right)
				{
					if (isOpen[x][y] == false)FieldView[x][y] = 11;
				}
			if (Keyboard::isKeyPressed(Keyboard::R)) restart(app);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				app.close();
			}
		}

		app.clear(Color::White);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (isLost(i, j) == true)
				{
					// метод для поражения
					text.setString("Вы проиграли");
					text.setPosition(app.getView().getCenter().x - 9 * n, app.getView().getCenter().y - 3 * n);
					//text.setColor(Color::Cyan);
					app.draw(text);
				}
				if (isWin() == true)
				{
					// метод для победы
					text.setString("Вы ВЫИГРАЛИ");
					text.setPosition(app.getView().getCenter().x - 9 * n, app.getView().getCenter().y - 3 * n);
					app.clear(Color::Yellow);
					app.draw(text);
					//text.setColor(Color::Magenta);
					app.display();
					break;
				}

				s.setTextureRect(IntRect(FieldView[i][j] * w, 0, w, w));
				s.setPosition(float(i * w), float(j * w));
				app.draw(s);
			}
		}
		app.display();
	}
}
void Game::restart(RenderWindow& app)
{
	std::cout << "New gamea: ";
	app.close();
	Game game(n);
	game.game();
}