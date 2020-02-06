#include <SFML\Graphics.hpp>

//class Entity : public sf::CircleShape
//{
//public:
//	Entity(float r) : CircleShape(r) {};
//
//};


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Window");
	Entity shape(100.f);
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color::Red);
	Entity shape2(100.f);
	shape2.setPosition(700, 700);
	shape2.setFillColor(sf::Color::Blue);

	std::vector<sf::Drawable*> drawables{};
	drawables.push_back(&shape);
	drawables.push_back(&shape2);
	shape.

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (auto drawable : drawables)
		{
			window.draw(*drawable);
		}
		window.display();
	}

}