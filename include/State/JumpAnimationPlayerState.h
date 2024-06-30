#pragma once
#include <SFML/Graphics.hpp>
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "Resources.h"

class Player;
class JumpAnimationPlayerState : public PlayerAnimationState {
public:
    JumpAnimationPlayerState(Player*);
    //virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    virtual void draw(const Player*, sf::RenderWindow&) override;
    void animate(float);
    virtual int getXOffset()const = 0;
    //virtual void jump(Player*) override {};
    //virtual void walk(Player*) override {};

protected: //לבדוק אם להעלות ממברים למעלה
    //sf::IntRect m_jumpFrame;
   // int m_currentFrame;
    //float m_frameTime;
    //float m_elapsedTime;
    float m_jumpVelocity = -400;
    float m_gravity;

private:
    float m_texutre_timer = 0;
    sf::Sprite m_sp;
    std::vector<sf::IntRect>* m_frames;
    int m_curr_frame = -1;
};