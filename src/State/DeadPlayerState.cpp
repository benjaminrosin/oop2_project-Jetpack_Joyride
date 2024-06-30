#include "State/DeadPlayerState.h"
#include "Player.h"
#include <iostream>

void DeadPlayerState::enter(Player* player)
{
	player->setNewSprite("Fall", Dead_t);
}

void DeadPlayerState::update(Player* player, float deltaTime)
{
	player->animate(deltaTime);
    player->move(sf::Vector2f(0.0f, m_jumpVelocity * deltaTime));
    m_jumpVelocity += m_gravity * deltaTime;
	if (player->getPosition().y > DEFULT_START_POINT)
	{
		player->setNewSprite("Dead", Dead_t);
		player->setPosition(sf::Vector2f(player->getPosition().x, DEFULT_START_POINT ));
		std::cout << player->getPosition().x << " " << player->getPosition().y << '\n';
		
	}
	
}
