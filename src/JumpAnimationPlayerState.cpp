
#include "JumpAnimationPlayerState.h"
#include "Player.h"

void JumpAnimationPlayerState::enter(Player* player)
{
    // Set jump animation frames
    m_currentFrame = 0;
    m_frameTime = 0.1f;  // זמן בין פריימים באנימציית הקפיצה
    m_elapsedTime = 0.0f;

    // נניח שיש לנו 4 פריימים לאנימציית הקפיצה
        //להעביר לריסורסז

    m_jumpFrames = { sf::IntRect(0, 0, 50, 50), sf::IntRect(50, 0, 50, 50), sf::IntRect(100, 0, 50, 50), sf::IntRect(150, 0, 50, 50) };
    player->setSpriteRect(m_jumpFrames[m_currentFrame]);

    // הגדרת מהירות הקפיצה
    m_jumpVelocity = -300.0f;
    m_gravity = 800.0f;
}

void JumpAnimationPlayerState::update(Player* player, float deltaTime)
{
    m_elapsedTime += deltaTime;

    // עדכון פריימים של האנימציה
    if (m_elapsedTime >= m_frameTime)
    {
        m_elapsedTime -= m_frameTime;
        m_currentFrame = (m_currentFrame + 1) % m_jumpFrames.size();
        player->setSpriteRect(m_jumpFrames[m_currentFrame]);
    }

    // עדכון תנועת הקפיצה
    //player->setMove(0, m_jumpVelocity * deltaTime);
    m_jumpVelocity += m_gravity * deltaTime;

    // בדיקת סיום הקפיצה (כאשר השחקן נוחת בחזרה)
  /*  if (player->sprite.getPosition().y >= 300.0f)
    {
        player->sprite.setPosition(player->sprite.getPosition().x, 300.0f);
        player->setState(std::make_unique<WalkAnimationPlayerState>());
    }*/
}

void JumpAnimationPlayerState::draw(Player* player, sf::RenderWindow& wind)
{
    wind.draw(player->getDrawable());
}
