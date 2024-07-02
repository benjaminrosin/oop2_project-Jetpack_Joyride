#pragma once
#include"State/WalkAnimationPlayerState.h"

class GravityPlayerState : public WalkAnimationPlayerState {
public:
    GravityPlayerState(Player*);
    //virtual void enter(Player*) override;
    virtual void update(Player*, float) override;

private:
    bool m_gravity = true;
};