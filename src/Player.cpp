#include "Player.h"
#include "State/RegularWalkState.h"
#include "State/TankWalkState.h"


Player::Player()
	: MovingGameObjects(Player_t, sf::Vector2f(0, DEFULT_START_POINT), "walking berry")
{
	setState(std::make_unique<RegularWalkState>(this));
	//setState(std::make_unique<TankWalkState>(this));

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

	if (m_sp.getPosition().y + v2f.y > DEFULT_START_POINT + 10)
	{
		v2f.y = 0;
	}

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

void Player::setPosition(sf::Vector2f v2p)
{
	m_sp.setPosition(v2p);
}

void Player::flip(int num)
{
	//auto currOrigin = m_sp.getOrigin();

	//m_sp.setOrigin(0,0);
	m_sp.setScale(sf::Vector2f(1, num));

	//m_sp.setOrigin(currOrigin);
	//m_sp.setOrigin({ 0, - m_sp.getGlobalBounds().height });
	//m_sp.setOrigin(0, m_sp.getGlobalBounds().height);
	//m_sp.setPosition(m_sp.getPosition() + sf::Vector2f(0, 5 + m_sp.getGlobalBounds().height));
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
