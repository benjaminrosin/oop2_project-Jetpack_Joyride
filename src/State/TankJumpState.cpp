#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Player.h"

void TankJumpState::enter(Player* player)
{
    player->setNewSprite("jumping tank", Tank_t);

    JumpAnimationPlayerState::enter(player);
}

void TankJumpState::update(Player* player, float deltaTime)
{
    JumpAnimationPlayerState::update(player, deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_jumpVelocity -= m_gravity * deltaTime * 0.90;
    }
    if (player->getPosition().y > DEFULT_START_POINT)
    {
        player->setState(std::make_unique<TankWalkState>());
    }
}

//void TankJumpState::jump(Player*)
//{
//
//}
