#include "Resources.h"
#include "State/JumpAnimationPlayerState.h"
#include "Player.h"

void JumpAnimationPlayerState::enter(Player* player)
{
    m_sp.setTexture(*Resources::getInstance().getTextureObject(Flame_t));
    m_frames = Resources::getInstance().getIntRect("Flame");

    m_sp.setTextureRect(m_frames->at(0));
    m_texutre_timer = 0;
    m_curr_frame = -1;

    animate(ANIMATION_RATE);

    // Set jump animation frames
    //m_currentFrame = 0;
    //m_frameTime = 0.1f;  // זמן בין פריימים באנימציית הקפיצה
    //m_elapsedTime = 0.0f;

        //להעביר לריסורסז

 //   player->setNewSprite("running berry");
    //m_jumpFrame = sf::IntRect(337.5, 0, 112.5, 150);
    //player->setSpriteRect(m_jumpFrame);

    // הגדרת מהירות הקפיצה
    m_jumpVelocity = -400.0f;
    m_gravity = 400.0f;
}

void JumpAnimationPlayerState::update(Player* player, float deltaTime)
{
    //std::cout << "tset jump";

    //player->setSpriteRect(m_jumpFrame);
    player->animate(deltaTime);
    animate(deltaTime);
    // Update jump movement
    if ((player->getPosition().y - player->getHeight() + m_jumpVelocity * deltaTime) < TOP_SCREEN_LIMIT) //add texture height
    {
        m_jumpVelocity = 0;
    }
    else
    {
        player->move(sf::Vector2f(0.0f, m_jumpVelocity * deltaTime));
        m_jumpVelocity += m_gravity * deltaTime;
    }
    //change to member and calculate right speed
    player->move({ 200 * deltaTime , 0 });

 //   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
 //   {
 //       m_jumpVelocity = -400.0f;
 //   }
 //   else if (player->getPosition().y > DEFULT_START_POINT)
 //   {
 //       player->setState(std::make_unique<WalkAnimationPlayerState>());
 //   }
}

void JumpAnimationPlayerState::draw(const Player* player, sf::RenderWindow& wind)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        auto pos = player->getPosition();
        pos.x += getXOffset();
        pos.y -= 15;
        m_sp.setPosition(pos);

        wind.draw(m_sp);
    }

}

void JumpAnimationPlayerState::animate(float time)
{
    m_texutre_timer += time;

    if (m_texutre_timer >= ANIMATION_RATE)
    {
        m_texutre_timer -= ANIMATION_RATE;
        m_curr_frame = (m_curr_frame + 1) % m_frames->size();
        m_sp.setTextureRect(m_frames->at(m_curr_frame));
    }
}

//void JumpAnimationPlayerState::draw(Player* player, sf::RenderWindow& wind)
//{
//    wind.draw(player->getDrawable());
//}
