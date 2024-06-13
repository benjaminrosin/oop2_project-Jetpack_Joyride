#pragma once
#include "PlayerAnimationState.h"
#include "WalkAnimationPlayerState.h"

class Player;
class JumpAnimationPlayerState : public PlayerAnimationState {
public:
    public:
        virtual void enter(Player*) override;
        virtual void update(Player*, float) override;
        virtual void draw(Player*, sf::RenderWindow&) override;
        virtual void jump(Player*) override {};
        virtual void walk(Player*) override {};

private: //לבדוק אם להעלות ממברים למעלה
    sf::IntRect m_jumpFrame;
   // int m_currentFrame;
    //float m_frameTime;
    //float m_elapsedTime;
    float m_jumpVelocity;
    float m_gravity;
    };