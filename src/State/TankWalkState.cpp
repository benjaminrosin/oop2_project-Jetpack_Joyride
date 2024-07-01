#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Player.h"

TankWalkState::TankWalkState(Player* player)
{
	player->setNewSprite("walking tank", Tank_t);
}

void TankWalkState::update(Player* player, float delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || player->getPosition().y < DEFULT_START_POINT)
	{
		player->setState(std::make_unique<TankJumpState>(player));
	}

	WalkAnimationPlayerState::update(player, delta_time);

}
