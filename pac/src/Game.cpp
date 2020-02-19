#include "Game.h"

Game::Game() : m_Window(sf::VideoMode(WIDTH, HEIGHT), "Pac")
{
	m_Window.clear();
	m_Window.setFramerateLimit(60);
}

void Game::run()
{
	while (m_Window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::addDrawObject(std::shared_ptr<Entity> drawable, std::string key)
{
	m_drawObjects.insert(std::pair<std::string, std::shared_ptr<Entity>>(key, drawable));
}

void Game::update()
{
	for (auto object : m_drawObjects)
		object.second->update();
}

void Game::render()
{
	m_Window.clear();
	for (auto drawable : m_drawObjects)
	{
		if(PLAYER == drawable.first)
			m_Window.setView((std::dynamic_pointer_cast<Player>(drawable.second))->getView());

		m_Window.draw(*drawable.second);
	}
	m_Window.display();
}

void Game::processEvents()
{
	sf::Event event;

	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_Window.close();
			break;
		}
	}
}
