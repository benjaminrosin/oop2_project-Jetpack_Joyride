#include "State/RegularWalkState.h"
#include "State/RegularJumpState.h"
#include "State/DeadPlayerState.h"
#include "Player.h"

void RegularJumpState::enter(Player* player)
{
	player->setNewSprite("jumping berry", Player_t);

	JumpAnimationPlayerState::enter(player);
}

void RegularJumpState::update(Player* player, float delta_time)
{
	JumpAnimationPlayerState::update(player, delta_time);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_jumpVelocity = -400.0f;
    }
    else if (player->getPosition().y > DEFULT_START_POINT)
    {
        player->setState(std::make_unique<RegularWalkState>());
    }
}

void RegularJumpState::die(Player*player)
{
    player->setState(std::make_unique<DeadPlayerState>());
}

//void RegularWalkState::jump(Player*)
//{
//
//}
