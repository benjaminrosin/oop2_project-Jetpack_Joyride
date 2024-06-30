#include "State/WalkAnimationPlayerState.h"
#include "Player.h"

void WalkAnimationPlayerState::update(Player* player, float deltaTime)
{
    // Update run animation frames
    player->animate(deltaTime);


    float moveSpeed = 200.0f; // מהירות ההליכה של השחקן
    player->move(sf::Vector2f(moveSpeed * deltaTime, 0));
}