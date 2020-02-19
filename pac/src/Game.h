#pragma once
#include <SFML\Graphics.hpp>
#include "Headers.h"




class Game
{
public:
	Game();
	void run();
	void addDrawObject(std::shared_ptr<Entity> drawable, std::string key);
private:
	sf::RenderWindow m_Window;
	//std::vector<std::shared_ptr<Entity>> m_drawObjects{};
	std::map<std::string, std::shared_ptr<Entity>> m_drawObjects{};

	void update();
	void render();
	void processEvents();
};

