#pragma once
#include"State/JumpAnimationPlayerState.h"

class RegularJumpState : public JumpAnimationPlayerState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    virtual int getXOffset()const override { return 15; };
    virtual void die(Player*) override;
        //virtual void draw(Player*, sf::RenderWindow&) override;
        //virtual void jump(Player*) override;

private:

};