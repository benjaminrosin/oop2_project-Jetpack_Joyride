#include "Resources.h"
#include "State/JumpAnimationPlayerState.h"
#include "Player.h"

JumpAnimationPlayerState::JumpAnimationPlayerState(Player* player)
{
    m_sp.setTexture(*Resources::getInstance().getTextureObject(Flame_t));
    m_frames = Resources::getInstance().getIntRect("Flame");

    m_sp.setTextureRect(m_frames->at(0));
    m_texutre_timer = 0;
    m_curr_frame = -1;

    animate(ANIMATION_RATE);

    // הגדרת מהירות הקפיצה
    m_jumpVelocity = -400.0f;
    m_gravity = 400.0f;
}

void JumpAnimationPlayerState::update(Player* player, float deltaTime)
{
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

