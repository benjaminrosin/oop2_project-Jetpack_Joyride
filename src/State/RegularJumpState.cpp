#include "State/RegularWalkState.h"
#include "State/RegularJumpState.h"
#include "State/DeadPlayerState.h"
#include "Objects/Player.h"

RegularJumpState::RegularJumpState(Player* player, int velocity)
    :JumpAnimationPlayerState(player)
{
	player->setNewSprite("jumping berry", Player_t);
    player->setVelocity(velocity);
}

void RegularJumpState::update(Player* player, float delta_time)
{
	JumpAnimationPlayerState::update(player, delta_time);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        player->setVelocity(-350);
    }
    else if (player->getPosition().y > DEFULT_START_POINT)
    {
        player->setState(std::make_unique<RegularWalkState>(player));
    }
}

void RegularJumpState::die(Player*player)
{
    player->setState(std::make_unique<DeadPlayerState>(player));
}

