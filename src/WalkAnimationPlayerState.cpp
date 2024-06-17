#include "WalkAnimationPlayerState.h"
#include "Player.h"
void WalkAnimationPlayerState::enter(Player* player)
{
    // Set run animation frames
    m_currentFrame = 0;
    m_frameTime = 0.1f;  // זמן בין פריימים באנימציית ההליכה
    m_elapsedTime = 0.0f;

    // נניח שיש לנו 4 פריימים לאנימציית ההליכה
    //להעביר לריסורסז
    m_walkFrames = { sf::IntRect(0, 0, 112.5, 150), sf::IntRect(112.5, 0, 112.5, 150), sf::IntRect(225, 0, 112.5, 150)};
    player->setSpriteRect(m_walkFrames[m_currentFrame]);
}

void WalkAnimationPlayerState::update(Player* player,float deltaTime)
{
    m_elapsedTime += deltaTime;

    // Update run animation frames
    if (m_elapsedTime >= m_frameTime)
    {
        m_elapsedTime -= m_frameTime;
        m_currentFrame = (m_currentFrame + 1) % m_walkFrames.size();
        player->setSpriteRect(m_walkFrames[m_currentFrame]);
    }

    // Update player's horizontal movement if needed
        // For simplicity, let's assume the player always moves to the right
    float moveSpeed = 200.0f; // מהירות ההליכה של השחקן
    player->move(sf::Vector2f(moveSpeed * deltaTime, 0));
}

//void WalkAnimationPlayerState::draw(Player* player, sf::RenderWindow& wind)
//{
//    wind.draw(player->getDrawable());
//}

void WalkAnimationPlayerState::jump(Player* player)
{
    player->setState(std::make_unique<JumpAnimationPlayerState>());
}
