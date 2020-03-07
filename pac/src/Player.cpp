#include "Player.h"

Player::Player()
{
	m_Shape.setSize(sf::Vector2f(30.f, 30.f));
	this->setPosition(WIDTH / 2, HEIGHT / 2);
	m_Camera.setCenter(this->getPosition());
	m_Camera.setSize(WIDTH, HEIGHT);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(Keys::LEFT))
	{
		this->sf::Transformable::move(m_backwardsSpeed);
		m_Camera.move(m_backwardsSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(Keys::RIGHT))
	{
		this->sf::Transformable::move(m_forwardSpeed);
		m_Camera.move(m_forwardSpeed);
	}
}

void Player::update()
{
	move();
}

const sf::View& Player::getView()
{
	return m_Camera;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Shape, states);
}