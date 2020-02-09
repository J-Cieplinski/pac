#include "Player.h"

Player::Player()
{
	m_Shape.setSize(sf::Vector2f(30.f, 30.f));
}

void Player::update()
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Shape, states);
}
