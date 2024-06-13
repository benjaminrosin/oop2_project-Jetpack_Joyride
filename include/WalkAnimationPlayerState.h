# pragma once
#include "PlayerAnimationState.h"
#include "JumpAnimationPlayerState.h"

class Player;
class WalkAnimationPlayerState : public PlayerAnimationState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    virtual void draw(Player*, sf::RenderWindow&) override;
    virtual void jump(Player*) override;
    virtual void walk(Player*) override {};

private://לבדוק אם להעלות ממברים למעלה
    std::vector<sf::IntRect> m_walkFrames;
    int m_currentFrame;
    float m_frameTime;
    float m_elapsedTime;
};