#include"Game.h"

using namespace sf;

void mainMenu(RenderWindow& app)
{
	Texture lev1, lev2, lev3, info, fon, about;

	lev1.loadFromFile("..\\level 1.png");
	lev2.loadFromFile("..\\level 2.png");
	lev3.loadFromFile("..\\level 3.png");
	info.loadFromFile("..\\info.png");
	about.loadFromFile("..\\about.png");
	fon.loadFromFile("..\\fon.png");

	Sprite level1(lev1), level2(lev2), level3(lev3), inform(info), background(fon), avout_S(about);

	bool isMenu = true;
	int ChooseMenu;

	level1.setPosition(-640, -250);
	level2.setPosition(-640, -150);
	level3.setPosition(-630, -80);
	inform.setPosition(-570, -10);
	background.setPosition(0, 0);

	while (isMenu)
	{
		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed) app.close();
		}
		ChooseMenu = 0;

		app.clear();
		level1.setColor(Color::Yellow);
		level2.setColor(Color::Yellow);
		level3.setColor(Color::Yellow);
		inform.setColor(Color::Yellow);

		if (IntRect(70, 80, 400, 50).contains(Mouse::getPosition(app))) { level1.setColor(Color::Magenta); ChooseMenu = 1; }
		if (IntRect(25, 150, 460, 50).contains(Mouse::getPosition(app))) { level2.setColor(Color::Magenta); ChooseMenu = 2; }
		if (IntRect(25, 250, 460, 50).contains(Mouse::getPosition(app))) { level3.setColor(Color::Magenta); ChooseMenu = 3; }
		if (IntRect(25, 320, 530, 50).contains(Mouse::getPosition(app))) { inform.setColor(Color::Magenta); ChooseMenu = 4; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (ChooseMenu == 1)
			{
				isMenu = false;
				app.close();
				Game game;
				game.game();

			}
			if (ChooseMenu == 2)
			{
				isMenu = false;
				app.close();
				Game game(10);
				game.game();
			}
			if (ChooseMenu == 3)
			{
				isMenu = false;
				app.close();
				Game game(12);
				game.game();
			}
			if (ChooseMenu == 4)
			{
				app.draw(avout_S);
				app.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape))
				{
					Event ev;

					while (app.pollEvent(ev))
					{
						if (ev.type == Event::Closed) app.close();
					}
				};
			}
		}
		app.draw(background);
		app.draw(level1);
		app.draw(level2);
		app.draw(level3);
		app.draw(inform);

		app.display();
	}
}
int main()
{
	srand(time(NULL));

	RenderWindow win(VideoMode(960, 540), "Menu!");

	mainMenu(win);

	return 0;
}