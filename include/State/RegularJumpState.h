#pragma once
#include"State/JumpAnimationPlayerState.h"

class RegularJumpState : public JumpAnimationPlayerState {
public:
    RegularJumpState(Player*);
    virtual void update(Player*, float) override;
    virtual int getXOffset()const override { return 10; };
    virtual void die(Player*) override;

private:

};