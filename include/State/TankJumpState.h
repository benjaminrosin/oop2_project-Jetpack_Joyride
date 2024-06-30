#pragma once
#include"State/JumpAnimationPlayerState.h"

class TankJumpState : public JumpAnimationPlayerState {
public:

    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    virtual int getXOffset()const override{ return 85; };
    //virtual void draw(Player*, sf::RenderWindow&) override;
    //virtual void jump(Player*) override;

private:

};