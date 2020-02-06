#include "Game.h"

Game::Game() : m_Window(sf::VideoMode(WIDTH, HEIGHT), "Pac")
{
	m_Window.clear();
	m_Window.setFramerateLimit(60);
}

void Game::run()
{
	while (m_Window.isOpen)
	{
		processEvents();
		update();
		render();
	}
}

void Game::addDrawObject(sf::Drawable* drawable)
{

}

void Game::update()
{
}

void Game::render()
{
	for(auto drawable: m_drawObjects)
		m_Window.draw(*drawable);

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
