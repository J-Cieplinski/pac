#pragma once
#include <SFML\Graphics.hpp>

#define WIDTH 1280
#define HEIGHT 720


class Game
{
public:
	Game();
	void run();
	void addDrawObject(sf::Drawable* drawable);
private:
	sf::RenderWindow m_Window;
	std::vector<sf::Drawable*> m_drawObjects;

	void update();
	void render();
	void processEvents();
};

