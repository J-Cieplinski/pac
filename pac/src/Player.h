#pragma once
#include "Headers.h"

class Player :
	public Entity, public sf::Transformable
{
public:
	Player();
	void update();
	const sf::View& getView();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape m_Shape;
	sf::View m_Camera;
	sf::Vector2f m_forwardSpeed{ 2.f, 0.f };
	sf::Vector2f m_backwardsSpeed{ -2.f, 0.f };
	void move();
};

struct Keys
{
	inline static auto LEFT = sf::Keyboard::Left;
	inline static auto RIGHT = sf::Keyboard::Right;
};