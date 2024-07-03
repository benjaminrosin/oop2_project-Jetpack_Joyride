#pragma once
#include"State/WalkAnimationPlayerState.h"

class RegularWalkState : public WalkAnimationPlayerState {
public:
    RegularWalkState(Player*);
    virtual void update(Player*, float) override;
    virtual void die(Player*) override;

private:

};