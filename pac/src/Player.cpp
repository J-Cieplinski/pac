#include "Player.h"

Player::Player()
{
	m_Shape.setSize(sf::Vector2f(30.f, 30.f));
	this->setPosition(WIDTH / 2 - 20, HEIGHT / 2 - 20);
	m_View.setCenter(this->getPosition());
	m_View.setSize(WIDTH, HEIGHT);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(Keys::LEFT))
	{
		this->sf::Transformable::move(m_backwardsSpeed);
		m_View.move(m_backwardsSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(Keys::RIGHT))
	{
		this->sf::Transformable::move(m_forwardSpeed);
		m_View.move(m_forwardSpeed);
	}
}

void Player::update()
{
	move();
}

const sf::View& Player::getView()
{
	return m_View;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Shape, states);
}