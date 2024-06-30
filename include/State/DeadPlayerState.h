#pragma once
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "State/JumpAnimationPlayerState.h"

class Player;
class DeadPlayerState : public PlayerAnimationState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;

protected: 
    float m_jumpVelocity =600;
    float m_gravity;
    
};