#include "Player.h"
#include "WalkAnimationPlayerState.h"

Player::Player()
	: MovingObject(Player_t, sf::Vector2f(MARGIN,SCREEN_SIZE.y-MARGIN))
{
	setState(std::make_unique<WalkAnimationPlayerState>());
	//m_currentState->enter(this);

}

void Player::move_and_change_sprite(float time, Object*)
{
	 
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

void Player::draw(sf::RenderWindow& wind)
{
	m_currentState->draw(this, wind);

}

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
	if (auto jumpState = dynamic_cast<JumpAnimationPlayerState*>(m_currentState.get()))
	{
		setState(std::make_unique<WalkAnimationPlayerState>());
	}
}


