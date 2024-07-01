#include "State/WalkAnimationPlayerState.h"
#include "Player.h"

void WalkAnimationPlayerState::update(Player* player, float deltaTime)
{
    // Update run animation frames
    player->animate(deltaTime);

    player->move(sf::Vector2f(deltaTime, 0));
}