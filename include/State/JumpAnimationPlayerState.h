#pragma once
#include <SFML/Graphics.hpp>
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "Resources.h"

class Player;
class JumpAnimationPlayerState : public PlayerAnimationState {
public:
    JumpAnimationPlayerState(Player*, object_code = Flame_t, std::string = "Flame");
    //virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    virtual void draw(const Player*, sf::RenderWindow&) override;
    void animate(float);
    virtual sf::Vector2f getFlameOffset()const = 0;
    //virtual void jump(Player*) override {};
    //virtual void walk(Player*) override {};

protected: //לבדוק אם להעלות ממברים למעלה
    //sf::IntRect m_jumpFrame;
   // int m_currentFrame;
    //float m_frameTime;
    //float m_elapsedTime;
    //float m_jumpVelocity = -400;
    //float m_gravity;
    sf::Sprite m_sp;

private:
    float m_texutre_timer = 0;
    std::vector<sf::IntRect>* m_frames;
    int m_curr_frame = -1;
};