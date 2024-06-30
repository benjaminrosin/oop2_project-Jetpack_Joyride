#include "State/DeadPlayerState.h"
#include "Player.h"
#include <iostream>

void DeadPlayerState::enter(Player* player)
{
	player->setAvoidStatus(true);
	player->setNewSprite("Fall", Dead_t);
}

void DeadPlayerState::update(Player* player, float deltaTime)
{
	player->animate(deltaTime);
    
	std::cout << m_jumpVelocity << '\n';
	if (player->getPosition().y > DEFULT_START_POINT)
	{
		player->setNewSprite("Dead", Dead_t);
		//player->setPosition(sf::Vector2f(player->getPosition().x, DEFULT_START_POINT ));
		player->move(sf::Vector2f(m_jumpVelocity * deltaTime, 0));
		if (m_jumpVelocity >= 0) {
			m_jumpVelocity -= m_gravity * deltaTime;
		}
	}
	else {
		player->move(sf::Vector2f(m_jumpVelocity * deltaTime, m_jumpVelocity * deltaTime));
	}
	
}
