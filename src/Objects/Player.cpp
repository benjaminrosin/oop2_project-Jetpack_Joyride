#include "Objects/Player.h"
#include "State/RegularWalkState.h"
#include "State/TankWalkState.h"


Player::Player()
	: MovingGameObjects(Player_t, sf::Vector2f(0, DEFULT_START_POINT), START_SPEED, 1, "walking berry")
{
	setState(std::make_unique<RegularWalkState>(this));

}


float Player::getHeight() const
{
	return m_sp.getLocalBounds().height;
}

void Player::setState(std::unique_ptr<PlayerAnimationState> state)
{
	m_currentState = std::move(state);
}

void Player::update(float deltaTime)
{
	m_currentState->update(this, deltaTime);
	updateSpeed(deltaTime * 3);
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

void Player::move(sf::Vector2f v2f)
{
	v2f.x *= m_speed;
	v2f.y *= m_jumpVelocity;

	if (m_sp.getPosition().y + v2f.y > DEFULT_START_POINT + 10)
	{
		v2f.y = 0;
	}

	m_sp.move(v2f);
}

void Player::move(float x)
{
	MovingGameObjects::move(x);
}

void Player::updateSpeed(float add)
{
	m_speed += add;
}

void Player::setVelocity(float num)
{
	m_jumpVelocity = num;
}

void Player::addVelocity(float num)
{
	m_jumpVelocity += num;
}

const float Player::getVelocity() const
{
	return m_jumpVelocity;
}

const float Player::getSpeed() const
{
	return m_speed;
}

const bool Player::isDead() const
{
	return m_dead;
}

void Player::dead()
{
	m_dead = true;
}

void Player::rotateSp(float angle)
{
	m_sp.setRotation(angle);
}

void Player::setPosition(sf::Vector2f v2p)
{
	m_sp.setPosition(v2p);
}

void Player::flip(int num)
{
	m_sp.setScale(sf::Vector2f(1, num));

}

std::unique_ptr<PlayerAnimationState> Player::getCurrState()
{
	return std::move(m_currentState);
}

