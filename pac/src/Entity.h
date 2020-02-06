#pragma once
#include <SFML\Graphics.hpp>

class Entity : private sf::Drawable
{
public:
	virtual void update() = 0;
	
};

class Player :
	public Entity, public sf::RectangleShape
{
public:
	Player() 
	{ 
		this->setSize(sf::Vector2f(20.f,20.f)); 
	};
	void update() {};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::RectangleShape::draw(target, states);
	}
};