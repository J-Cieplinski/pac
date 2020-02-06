#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

#define WIDTH 1280
#define HEIGHT 720


class Game
{
public:
	Game();
	void run();
	void addDrawObject(std::shared_ptr<Entity> drawable);
private:
	sf::RenderWindow m_Window;
	std::vector<std::shared_ptr<Entity>> m_drawObjects{};

	void update();
	void render();
	void processEvents();
};

