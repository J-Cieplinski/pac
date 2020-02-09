#pragma once
#include "Entity.h"

class Player :
	public Entity, public sf::Transformable
{
public:
	Player();;
	void update();;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape m_Shape;
};

