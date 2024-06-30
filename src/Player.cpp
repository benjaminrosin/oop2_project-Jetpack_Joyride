#include "Player.h"
#include "State/RegularWalkState.h"
#include "State/TankWalkState.h"

Player::Player()
	: MovingGameObjects(Player_t, sf::Vector2f(0, DEFULT_START_POINT), "walking berry")
{
	setState(std::make_unique<RegularWalkState>(this));

}


float Player::getHeight() const
{
	return m_sp.getGlobalBounds().height;
}

void Player::setState(std::unique_ptr<PlayerAnimationState> state)
{
	m_currentState = std::move(state);
	//m_currentState->enter(this);
}

void Player::update(float deltaTime)
{
	m_currentState->update(this, deltaTime);
}

void Player::playerDie()
{
	m_currentState->die(this);
}

bool Player::avoidCollisions() const
{
	return m_avoidCollisions;
}

void Player::setAvoidStatus(bool val)
{
	m_avoidCollisions = val;
}

void Player::draw(sf::RenderWindow& wind) const
{
	Object::draw(wind);
	m_currentState->draw(this, wind);
}

