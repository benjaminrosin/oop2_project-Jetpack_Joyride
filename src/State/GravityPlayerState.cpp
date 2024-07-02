#include "State/GravityPlayerState.h"
#include "Player.h"

GravityPlayerState::GravityPlayerState(Player* player, int gravity)
	:m_gravity(gravity), m_player(player)
//	:WalkAnimationPlayerState(m_gravityDir)
{
	player->setNewSprite("Gravity", Gravity_t);
	player->setVelocity(500);
	player->setScale(sf::Vector2f(1, m_gravity / GRAVITY));
	//set scale
}

GravityPlayerState::~GravityPlayerState()
{
	m_player->setScale({ 1,1 });
}

void GravityPlayerState::update(Player* player, float deltaTime)
{
	m_timer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_timer > 0.3)
	{
		flip();
	}
	else if((m_gravity > 0 &&(player->getPosition().y < DEFULT_START_POINT )) ||
			(m_gravity < 0 &&( player->getPosition().y > TOP_SCREEN_LIMIT)))
	{
		player->move(sf::Vector2f(deltaTime, m_gravity/GRAVITY * deltaTime));
	}
	else {
		WalkAnimationPlayerState::update(player, deltaTime);
	}
}

void GravityPlayerState::flip()
{
	m_gravity = -m_gravity;
	m_player->setScale(sf::Vector2f(1, m_gravity / GRAVITY));
	m_timer = 0;
}
