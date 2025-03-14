#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Objects/Player.h"

TankJumpState::TankJumpState(Player* player, int velocity)
    :JumpAnimationPlayerState(player)
{
    player->setNewSprite("jumping tank", Tank_t);
    player->setVelocity(velocity);
}

void TankJumpState::update(Player* player, float deltaTime)
{
    JumpAnimationPlayerState::update(player, deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        player->addVelocity( -GRAVITY * deltaTime * 0.90);
    }
    if (player->getPosition().y > DEFULT_START_POINT)
    {
        player->setState(std::make_unique<TankWalkState>(player));
    }
}
