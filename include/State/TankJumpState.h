#pragma once
#include"State/JumpAnimationPlayerState.h"

class TankJumpState : public JumpAnimationPlayerState {
public:
    TankJumpState(Player*, int = 0);
    virtual void update(Player*, float) override;
    virtual sf::Vector2f getFlameOffset()const override { return { 45, -15 }; };

private:

};