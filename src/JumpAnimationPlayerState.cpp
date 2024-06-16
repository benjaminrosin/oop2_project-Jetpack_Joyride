
#include "JumpAnimationPlayerState.h"
#include "Player.h"

void JumpAnimationPlayerState::enter(Player* player)
{
    // Set jump animation frames
    //m_currentFrame = 0;
    //m_frameTime = 0.1f;  // זמן בין פריימים באנימציית הקפיצה
    //m_elapsedTime = 0.0f;

        //להעביר לריסורסז

    m_jumpFrame = sf::IntRect(337.5, 0, 112.5, 150);
    player->setSpriteRect(m_jumpFrame);

    // הגדרת מהירות הקפיצה
    m_jumpVelocity = -400.0f;
    m_gravity = 100.0f;
}

void JumpAnimationPlayerState::update(Player* player, float deltaTime)
{
    //std::cout << "tset jump";

    player->setSpriteRect(m_jumpFrame);

    // Update jump movement
    if ((player->getDrawable().getGlobalBounds().top + m_jumpVelocity * deltaTime) < TOP_SCREEN_LIMIT)
    {
        m_jumpVelocity = 0;
    }
    else
    {
        player->setMove(0, m_jumpVelocity * deltaTime);
        m_jumpVelocity += m_gravity * deltaTime;
    }
    //change to member and calculate right speed
    player->setMove(100*deltaTime , 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_jumpVelocity = -400.0f;
        m_gravity = 100.0f;
    }
    // Check if spacebar is released to end the jump
    //if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
    else
    {
            m_gravity = 800.0f;
            if (player->getPosition().y >= DEFULT_START_POINT)
            {
                player->setPosition(player->getPosition().x, DEFULT_START_POINT);
                player->setState(std::make_unique<WalkAnimationPlayerState>());
            }
    }
}

//void JumpAnimationPlayerState::draw(Player* player, sf::RenderWindow& wind)
//{
//    wind.draw(player->getDrawable());
//}
