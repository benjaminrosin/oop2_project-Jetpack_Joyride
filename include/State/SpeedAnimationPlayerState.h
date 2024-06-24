#pragma once
#include <SFML/Graphics.hpp>
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "State/JumpAnimationPlayerState.h"
#include "Resources.h"

class Player;
class SpeedAnimationPlayerState : public PlayerAnimationState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    //virtual void draw(Player*, sf::RenderWindow&) override;
    virtual void jump(Player*) override;
    //virtual void walk(Player*) override {};

private: //לבדוק אם להעלות ממברים למעלה
    float m_speed = 10;
}
