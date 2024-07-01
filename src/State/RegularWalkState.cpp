#include "State/RegularWalkState.h"
#include "State/RegularJumpState.h"
#include "State/DeadPlayerState.h"
#include "Player.h"

RegularWalkState::RegularWalkState(Player* player)
{
	player->setNewSprite("walking berry", Player_t);
}

void RegularWalkState::update(Player* player, float delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || player->getPosition().y < DEFULT_START_POINT)
	{
		player->setState(std::make_unique<RegularJumpState>(player));
	}

	WalkAnimationPlayerState::update(player, delta_time);

}

void RegularWalkState::die(Player* player)
{
	player->setState(std::make_unique<DeadPlayerState>(player));
}

