#pragma once
#include"State/JumpAnimationPlayerState.h"

class TankJumpState : public JumpAnimationPlayerState {
public:
    TankJumpState(Player*);
    //virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    virtual int getXOffset()const override{ return 45; };

private:

};