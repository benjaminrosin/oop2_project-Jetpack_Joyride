#pragma once
#include"State/WalkAnimationPlayerState.h"
#include "Factory/PowerupFactory.h"

class TankWalkState : public WalkAnimationPlayerState {
public:
    TankWalkState(Player*);
    virtual void update(Player*, float) override;

private:
    static bool m_registered;
};