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
	return m_sp.getLocalBounds().height;
}

void Player::setState(std::unique_ptr<PlayerAnimationState> state)
{
	m_currentState = std::move(state);
}

void Player::update(float deltaTime)
{
	m_currentState->update(this, deltaTime);
	updateSpeed(deltaTime*3);
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
	v2f.x *= m_moveSpeed;
	v2f.y *= m_jumpVelocity;
	MovingGameObjects::move(v2f);
}

void Player::move(float x)
{
	MovingGameObjects::move(x);
}

void Player::updateSpeed(float add)
{
	m_moveSpeed += add;
	std::cout << m_moveSpeed << '\n';
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
	return m_moveSpeed;
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

std::unique_ptr<PlayerAnimationState> Player::getCurrState()
{
	return std::move(m_currentState);
}

//const std::unique_ptr<PlayerAnimationState>&& Player::getCurrState() const
//{
//	//return m_currentState.get();
//	return std::move(m_currentState);
//		//std::make_unique<PlayerAnimationState>(*m_currentState);
//}
//std::unique_ptr<PlayerAnimationState> Player::getCurrState() const
//{
//	//return std::move(m_currentState);
//}
