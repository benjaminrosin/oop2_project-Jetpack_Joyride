#include "State/DeadPlayerState.h"
#include "Player.h"

void DeadPlayerState::enter(Player* player)
{
	player->setNewSprite("Dead", Dead_t);
}

void DeadPlayerState::update(Player*, float)
{
}
