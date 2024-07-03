#include "State/WalkAnimationPlayerState.h"
#include "Objects/Player.h"

void WalkAnimationPlayerState::update(Player* player, float deltaTime)
{
    player->animate(deltaTime);
    player->move(sf::Vector2f(deltaTime, 0));
}