#include "State/RegularWalkState.h"
#include "State/RegularJumpState.h"
#include "Player.h"

void RegularWalkState::enter(Player* player)
{
	player->setNewSprite("walking berry", Player_t);
}

void RegularWalkState::update(Player* player, float delta_time)
{
	WalkAnimationPlayerState::update(player, delta_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player->setState(std::make_unique<RegularJumpState>());
	}
}

//void RegularWalkState::jump(Player*)
//{
//
//}
