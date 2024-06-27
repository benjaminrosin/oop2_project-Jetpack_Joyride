#include "State/PlayerAnimationState.h"
//#include "PlayerAnimationState.h"
#include "Player.h"
#include "State/RegularJumpState.h"
//#include <memory>
//
//void PlayerAnimationState::draw(Player* player, sf::RenderWindow& wind)
//{
//    wind.draw(player->getDrawable());
//}

void PlayerAnimationState::die(Player* player)
{
	player->setState(std::make_unique<RegularJumpState>());
}
