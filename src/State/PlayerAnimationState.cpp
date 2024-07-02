#include "State/PlayerAnimationState.h"
//#include "PlayerAnimationState.h"
#include "Player.h"
#include "State/RegularJumpState.h"
#include <memory>

void PlayerAnimationState::die(Player* player)
{
	player->setState(std::make_unique<RegularJumpState>(player, 0));
}
