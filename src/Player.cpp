#include "Player.h"
#include "WalkAnimationPlayerState.h"

Player::Player()
	: Object(Resources::getInstance().getTextureObject(Player_t),
		sf::Vector2f(MARGIN, DEFULT_START_POINT),
		Resources::getInstance().getIntRect(Player_t))
{
	//m_sp.setTexture(*Resources::getInstance().getTextureObject(Player_t));
	//m_sp.setPosition(DEFULT_START_POINT);
	//m_sp.setTextureRect(Resources::getInstance().getIntRect(obj));
	//m_sp.setOrigin(sf::Vector2f(0, Resources::getInstance().getIntRect(obj).height));

	setState(std::make_unique<WalkAnimationPlayerState>());
	//m_currentState->enter(this);

}

void Player::move_and_change_sprite(float time, Object*)
{
	 
}

float Player::getHeight() const
{
	return m_sp.getGlobalBounds().height;
}

void Player::setState(std::unique_ptr<PlayerAnimationState> state)
{
	m_currentState = std::move(state);
	m_currentState->enter(this);
}

void Player::update(float deltaTime)
{
	m_currentState->update(this, deltaTime);
}

//void Player::draw(sf::RenderWindow& wind)
//{
//	m_currentState->draw(this, wind);
//
//}

void Player::jump()
{
	m_currentState->jump(this);
}

void Player::walk()
{
	m_currentState->walk(this);
}

void Player::handleSpaceRelease()
{
	//овезк
	//if (auto jumpState = /*dynamic_cast<JumpAnimationPlayerState*>*/(m_currentState.get()))
	{
		//setState(std::make_unique<WalkAnimationPlayerState>());
	}
}




