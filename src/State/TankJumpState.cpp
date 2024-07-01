#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Player.h"

TankJumpState::TankJumpState(Player* player)
    :JumpAnimationPlayerState(player)
{
    player->setNewSprite("jumping tank", Tank_t);

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

//void TankJumpState::jump(Player*)
//{
//
//}
