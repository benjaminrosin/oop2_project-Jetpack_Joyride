#pragma once
#include"State/JumpAnimationPlayerState.h"

class RegularJumpState : public JumpAnimationPlayerState {
public:
    RegularJumpState(Player*);
    virtual void update(Player*, float) override;
    virtual sf::Vector2f getFlameOffset()const override { return { 10, -15 }; };
    virtual void die(Player*) override;

private:

};