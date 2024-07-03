#include "State/DeadPlayerState.h"
#include "Player.h"
#include <iostream>

DeadPlayerState::DeadPlayerState(Player* player)
{
	player->setAvoidStatus(true);
	player->setNewSprite("Fall", Dead_t);
	player->setVelocity(400);
}

void DeadPlayerState::update(Player* player, float deltaTime)
{
	player->animate(deltaTime);
    
	if (player->getPosition().y > DEFULT_START_POINT)
	{
		player->setNewSprite("Dead", Dead_t);
		player->move(sf::Vector2f(deltaTime, 0));
		player->updateSpeed( -GRAVITY * deltaTime);

		if (player->getSpeed() < 0)
		{
			player->dead();
		}
	}
	else {
		player->move(sf::Vector2f(deltaTime, deltaTime));
	}
	
}
