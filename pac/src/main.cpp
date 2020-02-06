#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Entity.h"



int main()
{
	std::shared_ptr<Player> player = std::make_shared<Player>(Player());
	/*player->setSize(sf::Vector2f(20, 20));
	player->setPosition(WIDTH / 2 - 20, HEIGHT / 2 - 20);
	player->setFillColor(sf::Color::Yellow);*/



	Game game;

	game.addDrawObject(player);

	game.run();
	

	
}